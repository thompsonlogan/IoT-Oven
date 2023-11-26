import { https } from "firebase-functions";
import { getDeviceDocument } from "./getDeviceDocumentHelper.js";

const getDeviceConfigBase = async (deviceId, ownerId) => await getDeviceDocument(deviceId, ownerId, "deviceConfiguration");

// HTTP function getDeviceConfig
const getDeviceConfigHttp = https.onRequest(async (req, res) => {
  // Device ID, Owner ID
  const deviceId = req.body.deviceId;
  const ownerId = req.body.ownerId;

  try {
    const configRs = await getDeviceConfigBase(deviceId, ownerId);
    res.send(configRs);
  } catch (ex) {
    console.error("Unable to get device configuration", ex);
    res.status(400).send({
      error: `Unable to get device configuration, ${ex}`,
    });
  }
});

// Callable function getDeviceConfig
const getDeviceConfigCallable = https.onCall(async (data, context) => {
  // Device ID, Owner ID
  const deviceId = data.deviceId;
  const ownerId = context.auth.uid;

  try {
    return await getDeviceConfigBase(deviceId, ownerId);
  } catch (ex) {
    console.error("Unable to get device configuration", ex);
    throw new https.HttpsError(
        "aborted",
        `Unable to get device configuration, ${ex}`,
        ex,
    );
  }
});

export default getDeviceConfigCallable;

export {
  getDeviceConfigHttp,
};
