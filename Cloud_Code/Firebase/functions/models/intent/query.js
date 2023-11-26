export default class Query {
  constructor(id, devices, devicesIDs) {
    this.requestId = id;
    this.payload = {
      "devices": {},
    };
    if (devices != null) {
      Object.keys(devices).forEach((id) => {
        devicesIDs.forEach((key) => {
          if (devices[id].id == key.id) {
            this.payload.devices[id] = devices[id].state;
          }
        });
      });
    }
  }
}
