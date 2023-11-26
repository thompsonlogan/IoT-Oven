import { pubsub } from "firebase-functions";
// import { firestore } from "firebase-admin";
import pkg from "firebase-admin";
const { firestore } = pkg;

// Function onlineState
export default pubsub.topic("online-state").onPublish(async (message) => {
  const logEntry = JSON.parse(Buffer.from(message.data, "base64").toString());

  let online;
  switch (logEntry.jsonPayload.eventType) {
    case "CONNECT":
      online = true;
      break;
    case "DISCONNECT":
      online = false;
      break;
    default:
      throw new Error(`Invalid type ${logEntry.jsonPayload.eventType}`);
  }

  const deviceId = logEntry.labels.device_id;
  const deviceRef = firestore().doc(`deviceState/${deviceId}`);
  try {
    await deviceRef.update({ "online": online });
    console.log(`Online state updated for ${deviceId}`);
  } catch (error) {
    console.error(`${deviceId} not registered`, error);
  }
});
