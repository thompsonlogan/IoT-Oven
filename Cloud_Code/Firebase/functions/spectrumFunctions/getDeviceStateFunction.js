import { https } from "firebase-functions";
import { firestore } from "../admin.js";
import { getDeviceDocument } from "./getDeviceDocumentHelper.js";

const getDeviceStateBase = async (deviceId, ownerId) => await getDeviceDocument(deviceId, ownerId, "deviceState");

// HTTP function getDeviceState
const getDeviceStateHttp = https.onRequest(async (req, res) => {
  // Device ID, Owner ID
  const deviceId = req.body.deviceId;
  const ownerId = req.body.ownerId;

  try {
    const propsRs = await getDeviceStateBase(deviceId, ownerId);
    res.send(propsRs);
  } catch (ex) {
    console.error("Unable to get device state", ex);
    res.status(400).send({
      error: `Unable to get device state, ${ex}`,
    });
  }
});

// Callable function getDeviceState
const getDeviceStateCallable = https.onCall(async (data, context) => {
  // Device ID, Owner ID
  const deviceId = data.deviceId;
  const ownerId = context.auth.uid;

  try {
    return await getDeviceStateBase(deviceId, ownerId);
  } catch (ex) {
    console.error("Unable to get device state", ex);
    throw new https.HttpsError(
        "aborted",
        `Unable to get device state, ${ex}`,
        ex,
    );
  }
});

export default getDeviceStateCallable;

export {
  getDeviceStateHttp,
};
