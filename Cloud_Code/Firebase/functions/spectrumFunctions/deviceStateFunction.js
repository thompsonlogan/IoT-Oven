import { pubsub } from "firebase-functions";
import { firestore } from "../admin.js";

/**
 * Cloud Function: Handle device state updates
 */
export default pubsub.topic("toaster-oven-state-topic").onPublish(async (message) => {
  const deviceId = message.attributes.deviceId;

  // Write the device state into firestore
  const deviceRef = firestore.doc(`deviceState/${deviceId}`);
  try {
    // Ensure the device is also marked as 'online' when state is updated
    await deviceRef.update({ "state": message.json, "online": true });
    console.log(`State updated for ${deviceId}`);
  } catch (error) {
    console.error(`${deviceId} not yet registered to a user`, error);
  }
});
