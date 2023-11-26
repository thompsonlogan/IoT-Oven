export default class Device {
  /**
   * Default device model
   * @param {*} id of the device
   * @param {*} data of the device
   */
  constructor(id, data) {
    this.id = id;
    this.owner = data.owner;
    this.properties = data.properties;
    this.config = data.config;
  }
}
