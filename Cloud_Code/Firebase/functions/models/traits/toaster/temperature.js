const attribute = {
  "temperatureRange": {
    "minThresholdCelsius": 65,
    "maxThresholdCelsius": 230,
  },
  "temperatureStepCelsius": 5,
  "temperatureUnitForUX": "C",
  "commandOnlyTemperatureControl": false,
  "queryOnlyTemperatureControl": false,
};

const name = "action.devices.traits.TemperatureControl";
const commands = ["action.devices.commands.SetTemperature"];
export class TemperatureControl {
  constructor(state) {
    if (state != null) {
      this.temperatureSetpointCelsius = state.temperatureSetpointCelsius;
      this.temperatureAmbientCelsius = state.temperatureAmbientCelsius;
    }
  }

  get name() {
    return name;
  }

  get commands() {
    return commands;
  }

  get attribute() {
    return attribute;
  }

  get reportState() {
    return {
      "temperatureSetpointCelsius": this.temperatureSetpointCelsius,
      "temperatureAmbientCelsius": this.temperatureAmbientCelsius,
    };
  }

  execute(command, params) {
    this.start = params.start;
    if (command == "action.devices.commands.SetTemperature") {
      this.temperatureSetpointCelsius = params.temperature;
    }
  }
}

