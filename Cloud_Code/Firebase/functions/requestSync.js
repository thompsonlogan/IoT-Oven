import functions from "firebase-functions";
import { homegraph, verifyAccountLink } from "./homegraphUtils.js";

export const add = functions.firestore.document("deviceConfiguration/{device}").onCreate(doRequestSync);

export const remove = functions.firestore.document("deviceConfiguration/{device}").onDelete(doRequestSync);

/*
 * Complete the RequestSync request through the HomeGraph API
 */
async function doRequestSync(snapshot, context) {
  // Obtain the device owner UID
  const userID = snapshot.data().owner;

  // Ensure the user has linked with a Google Assistant
  const linked = await verifyAccountLink(userID);
  if (!linked) {
    console.log(`User ${userID} not linked to Assistant`);
    return;
  }

  console.log(`Requesting SYNC for account: ${userID}`);

  // Request a SYNC intent
  await homegraph.devices.requestSync({
    requestBody: {
      agentUserId: userID,
      async: false,
    }
  });
}
