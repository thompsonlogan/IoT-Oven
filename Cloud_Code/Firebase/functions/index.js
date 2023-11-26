import onDeviceUpdate from "./spectrumFunctions/onDeviceUpdateFunction.js";
import onlineState from "./spectrumFunctions/onlineStateFunction.js";
import token from "./token.js";
import registerDevice from "./spectrumFunctions/registerDeviceFunction.js";
import createDevice from "./spectrumFunctions/createDeviceFunction.js";
import deviceState from "./spectrumFunctions/deviceStateFunction.js";
import fulfillment from "./fulfillment.js";
import getDeviceState from "./spectrumFunctions/getDeviceStateFunction.js";
import getDeviceConfig from "./spectrumFunctions/getDeviceConfigFunction.js";
import updateDeviceConfig from "./spectrumFunctions/updateDeviceConfigFunction.js";
import reportState from "./reportState.js";
import { add, remove } from "./requestSync.js";
import getDeviceProperties from "./spectrumFunctions/getDevicePropertiesFunction.js";
import listDevices from "./spectrumFunctions/listDevicesFunction.js";

export {
  onDeviceUpdate,
  onlineState,
  token,
  registerDevice,
  createDevice,
  deviceState,
  fulfillment,
  getDeviceState,
  getDeviceConfig,
  updateDeviceConfig,
  reportState,
  add as syncOnAdd,
  remove as syncOnRemove,
  getDeviceProperties,
  listDevices,
};
