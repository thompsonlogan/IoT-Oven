import { firestore } from "./admin.js";
import { google } from "googleapis";
import { GoogleAuth } from "googleapis-common";

/*
 * Create an instance of HomeGraph.
 */
export const homegraph = google.homegraph({
  version: "v1",
  auth: new GoogleAuth({
    scopes: "https://www.googleapis.com/auth/homegraph",
  }),
});

/*
 * Check to ensure that the specified user has successfully
 * linked their account with their Google Assistant, which
 * allows them to utilize HomeGraph features.
 */
export async function verifyAccountLink(userID) {
  const userRef = firestore.doc(`users/${userID}`);
  const user = await userRef.get();

  return (user.exists && user.get("refresh_token") !== undefined);
}
