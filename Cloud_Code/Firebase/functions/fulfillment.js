import fs from "fs";
import path from "path";
import { smarthome } from "actions-on-google";
import * as functions from "firebase-functions";
import { FulfillmentControllerFactory } from "./controllers/fulfillment-controller.js";
import jsonwebtoken from "jsonwebtoken";
const { verify } = jsonwebtoken;

let jwt;
try {
  jwt = JSON.parse(
      fs.readFileSync(path.resolve("smart-home-key.json")).toString(),
  );
} catch (e) {
  functions.logger.warn("error reading service account key:", e);
  functions.logger.warn("reportState and requestSync operation will fail");
}

const api = smarthome({ jwt });
const fulfillmentController = FulfillmentControllerFactory.create();
const jwtSecret = process.env.JWT_SECRET;

api.onDisconnect(async (body, headers) => {
  try {
    const userId = validateCredentials(headers);
    return await fulfillmentController.onDisconnect(userId);
  } catch (error) {
    functions.logger.error("Unable to authenticate DISCONNECT request", error);
    return {
      requestId: body.requestId,
      payload: {
        errorCode: "authFailure",
        debugString: error.toString(),
      },
    };
  }
  // User unlinked their account, stop reporting state for user
});

api.onExecute(async (body, headers) => {
  try {
    validateCredentials(headers);
    return await fulfillmentController.onExecute(body);
  } catch (error) {
    functions.logger.error("Unable to authenticate EXECUTE request", error);
    return {
      requestId: body.requestId,
      payload: {
        errorCode: "authFailure",
        debugString: error.toString(),
      },
    };
  }
});

api.onQuery(async (body, headers) => {
  try {
    validateCredentials(headers);
    return await fulfillmentController.onQuery(body);
  } catch (error) {
    functions.logger.error("Unable to authenticate QUERY request", error);
    return {
      requestId: body.requestId,
      payload: {
        errorCode: "authFailure",
        debugString: error.toString(),
      },
    };
  }
});

api.onSync(async (body, headers) => {
  try {
    console.log(`Validating user with Headers = ${JSON.stringify(headers)}`);
    const userId = validateCredentials(headers);
    const syncRes = await fulfillmentController.onSync(body, userId);
    console.log(`OnSync Response = ${JSON.stringify(syncRes)}`);

    return syncRes;
  } catch (error) {
    functions.logger.error("Unable to authenticate SYNC request", error);
    return {
      requestId: body.requestId,
      payload: {
        errorCode: "authFailure",
        debugString: error.toString(),
      },
    };
  }
});

/**
 * Verify the request credentials provided by the caller.
 * If successful, return UID encoded in the token.
 */
function validateCredentials(headers) {
  if (headers.authorization === undefined || !headers.authorization.startsWith("Bearer ")) {
    throw new Error("Request missing valid authorization");
  }

  const token = headers.authorization.split("Bearer ")[1];
  const decoded = verify(token, jwtSecret);

  return decoded.sub;
}

export default functions.runWith({
  secrets: ["JWT_SECRET"],
}).https.onRequest(api);
