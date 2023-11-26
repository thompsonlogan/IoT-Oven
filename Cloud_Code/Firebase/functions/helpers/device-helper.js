import DeviceFactory from "./device-factory.js";
export class DeviceHelper {
  /**
   * Device helper for creating device models from firestore helper
   * @param {FirestoreHelper} firestoreHelper
   */
  constructor(firestoreHelper) {
    this.firestoreHelper = firestoreHelper;
  }

  /**
   * Get device models from the properties document
   * @param {*} devices
   * @returns A dictionary of id device pairs
   */
  async getDeviceWithProperties(devices) {
    return await this.getDeviceSet("deviceProperties", devices);
  }

  /**
   * Get device models from the state document
   * @param {*} devices
   * @returns A dictionary of id device pairs
   */
  async getDevicesWithStates(devices) {
    return await this.getDeviceSet("deviceState", devices);
  }

  /**
   * For each device create the device model from the endpoint
   * @param {string} endpoint the
   * @param {*} devices
   * @returns A dictionary of id device pairs
   */
  async getDeviceSet(endpoint, devices) {
    const deviceSet = {};
    for (const target of devices) {
      try {
        const data = await this.firestoreHelper.getEndpointData(`${endpoint}/${target.id}`);

        const device = DeviceFactory.createDevice(target.id, data);
        deviceSet[device.id] = device;
      } catch (error) {
        deviceSet[target.id] = error;
      }
    }
    return deviceSet;
  }

  /**
   * Get the registered devices from the user
   * @param {string} userId
   * @returns all devices registered to the requested user
   */
  async getAllRegisteredDevices(userId) {
    const userDeviceDocuments = await this.firestoreHelper.getUserDeviceDocuments(userId);

    const deviceMetadataList = userDeviceDocuments.map((doc) => {
      const data = doc.data();
      const device = DeviceFactory.createDevice(doc.id, data);
      return device.metadata;
    });

    return deviceMetadataList;
  }
}
