import { https } from "firebase-functions";
import { firestore } from "../admin.js";

const listDeviceDocuments = async (collectionRef, ownerId) => {
  const docs = (await collectionRef.where('owner', '==', ownerId).get()).docs;
  return Object.assign({}, ...docs.map(d => ({ [d.id]: d.data() })));
};

const listDevicesBase = async (ownerId) => {
  if (!ownerId) {
    throw new Error("property \"ownerId\" was null or empty");
  }

  const propCollection = firestore.collection('deviceProperties');
  const props = await listDeviceDocuments(propCollection, ownerId);

  return props;
};

// HTTP function listDevices
const listDevicesHttp = https.onRequest(async (req, res) => {
  // Owner ID
  const ownerId = req.body.ownerId;

  try {
    const listRs = await listDevicesBase(ownerId);
    res.send(listRs);
  } catch (ex) {
    console.error("Unable to list devices", ex);
    res.status(400).send({
      error: `Unable to list devices, ${ex}`,
    });
  }
});

// Callable function listDevices
const listDevicesCallable = https.onCall(async (data, context) => {
  // Owner ID
  const ownerId = context.auth.uid;

  try {
    return await listDevicesBase(ownerId);
  } catch (ex) {
    console.error("Unable to list devices", ex);
    throw new https.HttpsError(
      "aborted",
      `Unable to list devices, ${ex}`,
      ex,
    );
  }
});

export default listDevicesCallable;

export {
  listDevicesHttp,
  listDeviceDocuments,
};
