import functions from "firebase-functions";
import { homegraph, verifyAccountLink } from "./homegraphUtils.js";
import DeviceFactory from "./helpers/device-factory.js";

/**
 * Trigger ReportState call when a device's state is modified.
 */
export default functions.firestore.document("deviceState/{device}").onUpdate(async (change, context) => {
  // Create a new Toaster model given the updated device state from Firestore
  const deviceID = context.params.device;
  console.log(`Reporting state with ID = ${deviceID} and Data = ${change.after.data()}`);
  const device = DeviceFactory.createDevice(deviceID, change.after.data());

  // Check if user has linked to Assistant
  const linked = await verifyAccountLink(device.owner);
  if (!linked) {
    console.log(`User ${device.owner} not linked to Assistant`);
    return;
  }

  // Determine the data of the device that should be updated
  const report = {};
  report[device.id] = device.reportState;

  console.log("Sending state report", report);

  // Update state data of HomeGraph
  await homegraph.devices.reportStateAndNotification({
    agentUserId: device.owner,
    requestId: ("request-id-" + device.owner),
    payload: {
      devices: {
        states: report,
      },
    },
  });
});
