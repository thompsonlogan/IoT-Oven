import { https } from "firebase-functions";
import { firestore } from "../admin.js";
import { getDeviceDocument } from "./getDeviceDocumentHelper.js";

const getDevicePropertiesBase = async (deviceId, ownerId) => await getDeviceDocument(deviceId, ownerId, "deviceProperties");

// HTTP function getDeviceProperties
const getDevicePropertiesHttp = https.onRequest(async (req, res) => {
  // Device ID, Owner ID
  const deviceId = req.body.deviceId;
  const ownerId = req.body.ownerId;

  try {
    const propsRs = await getDevicePropertiesBase(deviceId, ownerId);
    res.send(propsRs);
  } catch (ex) {
    console.error("Unable to get device state", ex);
    res.status(400).send({
      error: `Unable to get device state, ${ex}`,
    });
  }
});

// Callable function getDeviceProperties
const getDevicePropertiesCallable = https.onCall(async (data, context) => {
  // Device ID, Owner ID
  const deviceId = data.deviceId;
  const ownerId = context.auth.uid;

  try {
    return await getDevicePropertiesBase(deviceId, ownerId);
  } catch (ex) {
    console.error("Unable to get device state", ex);
    throw new https.HttpsError(
        "aborted",
        `Unable to get device state, ${ex}`,
        ex,
    );
  }
});

export default getDevicePropertiesCallable;

export {
  getDevicePropertiesHttp,
};
