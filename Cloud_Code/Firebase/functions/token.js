import firebase from "firebase-functions";
import jwt from "jsonwebtoken";
import { auth, firestore } from "./admin.js";
import "dotenv/config";

const JWT_SECRET = process.env.JWT_SECRET;
const JWT_AUD = process.env.JWT_AUDIENCE;
const JWT_CLIENT_SECRET = process.env.JWT_CLIENT_SECRET;

/**
 * Generates an authorization code from the given request.
 */
async function handleAuthorizationCode(request, response) {
  console.log("Authorization Code Grant Received");

  try {
    // Auth code is a Firebase ID token
    const decodedToken = await auth.verifyIdToken(request.body.code);

    // Verify UID exists in our database
    const result = await auth.getUser(decodedToken.uid);

    // Encode the user info as a JWT
    const refresh = jwt.sign({
      sub: result.uid,
      aud: JWT_AUD,
    }, JWT_SECRET);

    // Generate an initial access token
    const access = await getAccessToken(refresh, JWT_SECRET);

    // Register this refresh token for the given user
    const userRef = firestore.doc(`users/${result.uid}`);
    await userRef.set({ "refresh_token": refresh });

    // Respond with the credentials
    const credentials = {
      token_type: "Bearer",
      access_token: access,
      refresh_token: refresh,
      expires_in: 3600
    };
    
    console.log("Issued refresh token", credentials);
    response.status(200).send(credentials);
  } catch (error) {
    console.error("Unable to issue refresh token", error);
    response.status(400).send({ "error": "invalid_grant" });
  }
}

/**
 * Generates a refresh token from the given request.
 */
async function handleRefreshToken(request, response) {
  console.log("Refresh Token Grant Received");

  try {
    const refreshToken = request.body.refresh_token;

    // Validate token parameters
    const decodedToken = jwt.verify(refreshToken, JWT_SECRET);
    if (decodedToken.aud !== JWT_AUD) {
      throw new Error(`Unexpected client_id in token: ${decodedToken.aud}`);
    }

    // Verify UID exists in our database
    const result = await auth.getUser(decodedToken.sub);
    const userRef = firestore.doc(`users/${result.uid}`);
    const user = await userRef.get();

    // Verify incoming token matches our stored refresh token
    const validToken = user.data().refresh_token;
    if (JSON.stringify(validToken) !== JSON.stringify(refreshToken)) {
      throw new Error(`Invalid refresh token received: ${refreshToken}`);
    }

    // Obtain a new access token
    const token = await getAccessToken(refreshToken, JWT_SECRET);

    // Respond with the credentials
    const credentials = {
      token_type: "Bearer",
      access_token: token,
      expires_in: 3600
    };

    console.log("Issued access token", credentials);
    response.status(200).send(credentials);
  } catch (error) {
    console.error("Unable to issue access token", error);
    response.status(400).send({ "error": "invalid_grant" });
  }
}

/**
 * Exchanges a refresh token for an access token.
 */
async function getAccessToken(refreshToken, secret) {
  console.log("Obtaining access token");

  // Validate incoming token
  const decoded = jwt.verify(refreshToken, secret);

  // Re-encode with an expiration time
  return jwt.sign({
    sub: decoded.sub,
    aud: decoded.aud,
  }, secret, {
    expiresIn: "1h",
  });
}

/**
 * Called whenever a client access the token HTTP endpoint hosted on Google Cloud Functions.
 * - The "secrets" runWith option specifies the secrets to use from those stored in the 
 *   Google Secret Manager section of our Google Cloud project.
 */
export default firebase.runWith({
  secrets: ["JWT_SECRET", "JWT_CLIENT_SECRET"],
}).https.onRequest(async (request, response) => {
  if (request.body.client_id !== JWT_AUD ||
    request.body.client_secret !== JWT_CLIENT_SECRET) {
    response.status(400).send({ "error": "invalid_grant" });
    return;
  }

  if (request.body.grant_type === "authorization_code") {
    await handleAuthorizationCode(request, response);
  } else if (request.body.grant_type === "refresh_token") {
    await handleRefreshToken(request, response);
  } else {
    // Invalid request
    console.error(`Invalid request type: ${request.body.grant_type}`);
    response.status(400).send({ "error": "invalid_grant" });
  }
});
