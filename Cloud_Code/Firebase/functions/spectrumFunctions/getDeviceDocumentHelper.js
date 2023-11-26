import { firestore } from "../admin.js";

const getRefData = async (deviceId, ownerId, ref) => {
  const doc = await ref.get();
  // make sure device config exists
  if (!doc.exists) {
    throw new Error(`device ${deviceId} state is not present`);
  }

  const data = doc.data();
  // Wrong owner ID
  if (data.owner != ownerId) {
    throw new Error("This user does not have access to this device");
  }

  return data;
};

const getDeviceDocument = async (deviceId, ownerId, collectionName) => {
  if (!deviceId) {
    throw new Error("property \"deviceId\" was null or empty");
  }
  if (!ownerId) {
    throw new Error("property \"ownerId\" was null or empty");
  }

  const configRef = firestore.doc(`${collectionName}/${deviceId}`);

  return await getRefData(deviceId, ownerId, configRef);
};

export {
  getRefData,
  getDeviceDocument,
};
