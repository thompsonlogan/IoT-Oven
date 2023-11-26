import Device from "./device-model.js";
import { ToasterCook } from "../traits/toaster/cook.js";
import { ToasterOnOff } from "../traits/toaster/on_off.js";
import { TemperatureControl } from "../traits/toaster/temperature.js";
import { Timer } from "../traits/toaster/timer.js";

const type = "action.devices.types.OVEN";

/**
 * Traits for a toaster device
 */
export default class Toaster extends Device {
  /**
   * Creates the toaster model
   * @param {*} id of the device
   * @param {*} data to pull properties from
   */
  constructor(id, data) {
    super(id, data);
    this.traits = [
      new ToasterCook(data?.state),
      new ToasterOnOff(data?.state),
      new TemperatureControl(data?.state),
      new Timer(data?.state),
    ];
    this.online = data?.online;
  }

  /**
   * Get all attributes from traits that have a attribute
   */
  get attributes() {
    return Object.assign({},
        ...(this.traits.filter((trait) => "attribute" in trait).flatMap((trait) => trait.attribute)));
  }

  /**
   * Ge the fulfillment type of the device
   */
  get type() {
    return type;
  }

  /**
   * Gets all the fulfillment trait names
   */
  get traitsName() {
    return this.traits.flatMap((trait) => trait.name);
  }

  /**
   * Returns metadata of the device. Used for sync request
   */
  get metadata() {
    return {
      id: this.id,
      type: this.type,
      traits: this.traits.flatMap((trait) => trait.name),
      name: {
        name: this.properties?.name,
      },
      willReportState: true,
      attributes: this.attributes,
    };
  }

  /**
   * Returns the current state of the device
   */
  get state() {
    const report = Object.assign({},
        ...(this.traits.filter((trait) => "reportState" in trait).flatMap((trait) => trait.reportState)),
        { "online": this.online });
    return report;
  }

  /**
   * Performs the execution intent from fulfillment
   * @param {*} execution from fulfillment
   * @returns the new state changed state
   */
  execute(execution) {
    if (this.online == false) {
      throw new Error("deviceOffline");
    }
    const trait = this.traits.find((t) => t.commands.includes(execution.command));
    trait.execute(execution.command, execution.params);
    return Object.assign({}, trait.reportState, { online: this.online });
  }
}
