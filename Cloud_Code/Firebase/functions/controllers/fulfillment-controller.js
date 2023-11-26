import { DeviceHelper } from "../helpers/device-helper.js";
import FirestoreHelperFactory from "../helpers/firestore-helper.js";
import Execute, { Pending, Error } from "../models/intent/execute.js";
import Query from "../models/intent/query.js";
import Sync from "../models/intent/sync.js";

class FulfillmentControllerFactory {
  /**
   * Creates the default Fulfillment controller using firestore and deviceHelper
   * @returns FulfillmentController
   */
  static create() {
    const firestore = FirestoreHelperFactory.createHelper();
    const deviceHelper = new DeviceHelper(firestore);
    return new FulfillmentController(deviceHelper, firestore);
  }
}
class FulfillmentController {
  /**
   * Creates the fullfilmentController. Used for fulfillment intents
   * @param {*} deviceHelper device helper
   * @param {*} firestore database
   */
  constructor(deviceHelper, firestore) {
    this.deviceHelper = deviceHelper;
    this.firestore = firestore;
  }

  /**
   * Runs the execute intent
   * @param {*} body the body of the request
   * @returns Execute response
   */
  async onExecute(body) {
    const commands = [];


    for (const command of body.inputs[0].payload.commands) {
      const deviceSet = await this.deviceHelper.getDevicesWithStates(command.devices);
      for (const [id, device] of Object.entries(deviceSet)) {
        for (const e of command.execution) {
          try {
            if (device && device.stack && device.message) {
              // The device is likely an error. instanceof does not work in this case. =(
              throw device;
            }
            const updatedState = device.execute(e);
            await this.firestore.updateDevice(device);
            let currentCommand = commands.find((c) => c instanceof Pending && JSON.stringify(c.states) == JSON.stringify(updatedState));
            if (currentCommand == null) {
              currentCommand = new Pending(updatedState);
              commands.push(currentCommand);
            }
            currentCommand.ids.push(id);
          } catch (error) {
            let currentCommand = commands.find((c) => c.errorCode == error);
            if (currentCommand == null) {
              currentCommand = new Error(error.message);
              commands.push(currentCommand);
            }
            currentCommand.ids.push(id);
          }
        }
      }
    }

    return new Execute(body.requestId, commands);
  }

  /**
   * Runs the disconnect intent for fulfillment. This will delete the user from the users collection
   * @param {*} userId
   * @returns empty response
   */
  async onDisconnect(userId) {
    await this.firestore.deleteUser(userId);
    return {};
  }

  /**
   * Runs the query intent of fulfillment
   * @param {*} body of the request
   * @returns Query Response
   */
  async onQuery(body) {
    const deviceSet = await this.deviceHelper.getDevicesWithStates(body.inputs[0].payload.devices);
    const deviceKeys = [];

    body.inputs[0].payload.devices.forEach(function(element) {
      deviceKeys.push(element);
    });
    return new Query(body.requestId, deviceSet, deviceKeys);
  }

  /**
   * Runs the Sync intent of fulfillment
   * @param {*} body of the request
   * @param {*} userId
   * @returns Sync Response
   */
  async onSync(body, userId) {
    const deviceMetadataList = await this.deviceHelper.getAllRegisteredDevices(userId);
    return new Sync(body.requestId, userId, deviceMetadataList);
  }
}

export { FulfillmentControllerFactory, FulfillmentController };
