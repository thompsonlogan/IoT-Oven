import pizza from "../../food_presets/pizza.js";
import bagel from "../../food_presets/bagel.js";

const foodPresets = [
  pizza,
  bagel,
];

const supportedCookingModes = [
  "BAKE",
  "FRY",
  "ROAST",
  "BROIL",
  "WARM",
];

const attribute = {
  "supportedCookingModes": supportedCookingModes,
  "foodPresets": foodPresets,
};

const name = "action.devices.traits.Cook";
const commands = ["action.devices.commands.Cook"];
export class ToasterCook {
  constructor(state) {
    if (state != null) {
      this.currentCookingMode = state.currentCookingMode;
      this.currentFoodPreset = state.currentFoodPreset;
      this.currentFoodQuantity = state.currentFoodQuantity;
      this.currentFoodUnit = state.currentFoodUnit;
      this.start = state.start;
    }
  }

  get name() {
    return name;
  }

  get commands() {
    return commands;
  }

  get supportedCookingModes() {
    return supportedCookingModes;
  }

  get foodPresets() {
    return foodPresets;
  }

  get attribute() {
    return attribute;
  }

  get reportState() {
    return {
      "start": this.start,
      "currentCookingMode": this.currentCookingMode,
      "currentFoodPreset": this.currentFoodPreset,
      "currentFoodQuantity": this.currentFoodQuantity,
      "currentFoodUnit": this.currentFoodUnit,
    };
  }

  execute(command, params) {
    if (command == "action.devices.commands.Cook") {
      this.start = params.start;
      if ("cookingMode" in params) {
        this.currentCookingMode = params.cookingMode;
      }
      if ("foodPreset" in params) {
        this.currentFoodPreset = params.foodPreset;
      }
      if ("quantity" in params) {
        this.currentFoodQuantity = params.quantity;
      }
      if ("unit" in params) {
        this.currentFoodUnit = params.unit;
      }
    }
  }
}

