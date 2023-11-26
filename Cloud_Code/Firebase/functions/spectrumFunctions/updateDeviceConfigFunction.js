import { https } from "firebase-functions";
import { firestore } from "../admin.js";

const updateDocument = async (configRef, ownerId, data) => {
  const configDoc = await configRef.get();

  // Wrong owner ID
  if (configDoc.data().owner != ownerId) {
    throw new Error("This user does not have access to this device");
  }

  // Config document does not exist
  if (!configDoc.exists) {
    throw new Error("Config document for the device does not exist");
  }

  await configRef.update("config", data);
};

const updateDeviceConfigBase = async (deviceId, ownerId, config) => {
  if (!deviceId) {
    throw new Error("property \"deviceId\" was null or empty");
  }
  if (!ownerId) {
    throw new Error("property \"ownerId\" was null or empty");
  }
  if (!config) {
    throw new Error("property \"config\" was null or empty");
  }

  const configRef = firestore.doc(`deviceConfiguration/${deviceId}`);
  await updateDocument(configRef, ownerId, config);

  console.log(`Update device config for device ${deviceId}`);

  return `Successfully updated device config for device ${deviceId}`;
};

// HTTP function registerDevice
const updateDeviceConfigHttp = https.onRequest(async (req, res) => {
  // Device ID, Owner ID, Public Key
  const deviceId = req.body.deviceId;
  const ownerId = req.body.ownerId;
  const config = req.body.config;

  try {
    const updateRes = await updateDeviceConfigBase(deviceId, ownerId, config);
    res.send(updateRes);
  } catch (ex) {
    console.error("Unable to register new device", ex);
    res.status(400).send({
      error: `Unable to register new device, ${ex}`,
    });
  }
});

const updateDeviceConfigCallable = https.onCall(async (data, context) => {
  // Device ID, Owner ID, Public Key
  const deviceId = data.deviceId;
  const ownerId = context.auth.uid;
  const config = data.config;

  try {
    return await updateDeviceConfigBase(deviceId, ownerId, config);
  } catch (ex) {
    console.error("Unable to register new device", ex);
    throw new https.HttpsError(
        "aborted",
        `Unable to register new device, ${ex}`,
        ex,
    );
  }
});

export default updateDeviceConfigCallable;

export {
  updateDeviceConfigHttp,
  updateDocument,
};
