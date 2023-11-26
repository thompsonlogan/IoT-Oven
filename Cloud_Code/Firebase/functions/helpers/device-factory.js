import Toaster from "../models/devices/toaster.js";

export default class DeviceFactory {
  /**
   * Creates the appropriate device model based on the type in the data
   * @param {string} id of the device
   * @param {*} data from firestore
   * @returns the device model based on the type
   */
  static createDevice(id, data) {
    switch (data.type) {
      case "toaster":
        return new Toaster(id, data);
      default:
        throw new Error(`Invalid device type found in ${data.id}: ${data.type}`);
    }
  }
}
