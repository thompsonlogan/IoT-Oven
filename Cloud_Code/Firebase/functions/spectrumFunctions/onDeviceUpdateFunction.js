import { firestore } from "firebase-functions";
import { getRegistryPath, getClient } from "./iotClientHelper.js";

/**
 * Cloud Function: Handle device configuration changes
 */
export default firestore.document("deviceConfiguration/{device}").onUpdate(async (change, context) => {
  const deviceId = context.params.device;
  const updates = change.after.data();

  const client = await getClient();

  // update the device config
  try {
    await updateConfig(client, deviceId, updates);
  } catch (error) {
    console.log(error);
  }
});

/**
 * Return a promise to publish the new device config to Cloud IoT Core
 */
async function updateConfig(client, deviceId, updates) {
  // device location
  const registryName = getRegistryPath();

  // request with the new device config
  const request = {
    name: `${registryName}/devices/${deviceId}`,
    binaryData: Buffer.from(JSON.stringify(updates["config"]))
        .toString("base64"),
  };

  // send the request to the cloud IoT
  await client.projects.locations.registries.devices.modifyCloudToDeviceConfig(request);
}
