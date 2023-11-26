import { https } from "firebase-functions";
import { firestore } from "../admin.js";
import { getRegistryPath, getClient } from "./iotClientHelper.js";

const getDevicePath = (path, id) => {
  return `${path}/devices/${id}`;
};

const getDeviceGetCredsReq = (devicePath) => {
  return {
    name: devicePath,
    fieldMask: "credentials",
  };
};

const getDevicePatchReq = (devicePath) => {
  return {
    name: devicePath,
    updateMask: "blocked",
    requestBody: {
      blocked: false,
    },
  };
};

const checkRefsDoExist = async (...docRefs) => {
  return (await Promise.all(
      docRefs.map(async (docRef) => await docRef.get()),
  ))
      .some((doc) => doc.exists);
};

const getDevice = async (client, getReq) => {
  return await client.projects.locations.registries.devices.get(getReq);
};

const keyExistsInCreds = (iotCreds, publicKey) => {
  const normalizeKey = (key) => {
    const chunks = key.match(/(-{5}BEGIN PUBLIC KEY-{5})|([^-\n]{64})|([^-\n]{1,64})|(-{5}END PUBLIC KEY-{5})/g);
    return chunks.join("\n");
  };

  return iotCreds.some((c) => normalizeKey(c.publicKey.key) === normalizeKey(publicKey));
};

const patchDevice = async (client, patchReq) => {
  return await client.projects.locations.registries.devices.patch(patchReq);
};

// const setupBatch = (batch, configRef, stateRef, propertiesRef, ownerId, nameOfDevice) => {
const setupBatch = (batch, refs, ownerId, nameOfDevice) => {
  // Create the config document
  batch.set(refs.config, {
    owner: ownerId,
    type: "toaster",
    config: {},
  });

  // Create the state document
  batch.set(refs.state, {
    owner: ownerId,
    type: "toaster",
    online: false,
    state: {},
  });

  // Create the properties document
  batch.set(refs.properties, {
    owner: ownerId,
    type: "toaster",
    properties: {
      name: nameOfDevice,
    },
  });

  return batch;
};

const registerDeviceBase = async (deviceId, ownerId, pubKey, deviceName) => {
  if (!deviceId) {
    throw new Error("property \"deviceId\" was null or empty");
  }
  if (!ownerId) {
    throw new Error("property \"ownerId\" was null or empty");
  }
  if (!pubKey) {
    throw new Error("property \"publicKey\" was null or empty");
  }
  if (!deviceName) {
    throw new Error("property \"deviceName\" was null or empty");
  }

  const client = await getClient();

  const refs = {
    config: firestore.doc(`deviceConfiguration/${deviceId}`),
    properties: firestore.doc(`deviceProperties/${deviceId}`),
    state: firestore.doc(`deviceState/${deviceId}`),
  };
  // make sure device doesn't exist in any existing document
  if (await checkRefsDoExist(refs.config, refs.properties, refs.state)) {
    throw new Error(`device ${deviceId} already exists`);
  }

  // Get device
  const registryPath = getRegistryPath();
  const devicePath = getDevicePath(registryPath, deviceId);
  const deviceGetCredsReq = getDeviceGetCredsReq(devicePath);
  const deviceCredsRes = await getDevice(client, deviceGetCredsReq);
  if (!deviceCredsRes) {
    throw new Error("error retrieving the device");
  }
  const iotCreds = deviceCredsRes.data.credentials;

  // Make sure at least one public key matches the passed key
  // Throw if all keys do not match the passed key
  if (!keyExistsInCreds(iotCreds, pubKey)) {
    throw new Error("public keys do not match");
  }

  const userRef = firestore.doc(`users/${ownerId}`);
  // make sure user does exist
  if (!await checkRefsDoExist(userRef)) {
    await userRef.create({});
  }

  // unblock device communication
  const devicePatchReq = getDevicePatchReq(devicePath);
  const devicePatchRes = await patchDevice(client, devicePatchReq);
  if (!devicePatchRes) {
    throw new Error("Error unblocking device communication");
  }

  // Batch changes
  // Batch the firestore device creation
  const batch = firestore.batch();
  // setupBatch(batch, configRef, stateRef, propertiesRef, ownerId, deviceName);
  setupBatch(batch, refs, ownerId, deviceName);
  await batch.commit();

  console.log(`Added device ${deviceId} for the user ${ownerId}`);

  return `Successfully registered ${deviceId} to user ${ownerId} and unblocked communication for the device`;
};

// HTTP function registerDevice
const registerDeviceHttp = https.onRequest(async (req, res) => {
  // Device ID, Owner ID, Public Key
  const deviceId = req.body.deviceId;
  const ownerId = req.body.ownerId;
  const pubKey = req.body.publicKey;
  const deviceName = req.body.deviceName;

  try {
    const registerRes = await registerDeviceBase(deviceId, ownerId, pubKey, deviceName);
    res.send(registerRes);
  } catch (ex) {
    console.error("Unable to register new device", ex);
    res.status(400).send({
      error: `Unable to register new device, ${ex}`,
    });
  }
});

const registerDeviceCallable = https.onCall(async (data, context) => {
  // Device ID, Owner ID, Public Key
  const deviceId = data.deviceId;
  const ownerId = context.auth.uid;
  const pubKey = data.publicKey;
  const deviceName = data.deviceName;

  try {
    return await registerDeviceBase(deviceId, ownerId, pubKey, deviceName);
  } catch (ex) {
    console.error("Unable to register new device", ex);
    throw new https.HttpsError(
        "aborted",
        `Unable to register new device, ${ex}`,
        ex,
    );
  }
});

export default registerDeviceCallable;

export {
  registerDeviceHttp,
  getClient,
  getRegistryPath,
  getDevicePath,
  getDeviceGetCredsReq,
  getDevicePatchReq,
  checkRefsDoExist,
  getDevice,
  keyExistsInCreds,
  patchDevice,
  setupBatch,
};
