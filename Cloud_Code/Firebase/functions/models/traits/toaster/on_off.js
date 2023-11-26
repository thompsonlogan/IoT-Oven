const attribute = {
  "queryOnlyOnOff": false,
  "commandOnlyOnOff": false,
};

const name = "action.devices.traits.OnOff";
const commands = ["action.devices.commands.OnOff"];

export class ToasterOnOff {
  constructor(state) {
    if (state != null) {
      this.on = state.on;
    }
  }

  get attribute() {
    return attribute;
  }

  get name() {
    return name;
  }

  get commands() {
    return commands;
  }

  get reportState() {
    return {
      "on": this.on,
    };
  }

  execute(command, params) {
    if (command == "action.devices.commands.OnOff") {
      this.on = params.on;
    }
  }
}
