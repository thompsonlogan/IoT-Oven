import Toaster from "../../models/devices/toaster.js";

import { expect } from "chai";


describe("Toaster Tests", function() {
  let testToaster;

  before(function() {
    const state = {
      "on": false,
      "start": true,
      "currentCookingMode": "BAKE",
      "currentFoodPreset": "PIZZA",
      "currentFoodQuantity": 1,
      "currentFoodUnit": "NO_UNITS",
    };
    const properties = {
      "name": "Test Toaster",
    };
    testToaster = new Toaster("testToaster", { "owner": "Test Owner", "state": state, "properties": properties, "online": true });
  });

  describe("Test attribute returns expected", function() {
    it("Should return the toaster attributes from all the traits of the toaster", function() {
      expect(testToaster.attributes).to.deep.equal(
          {
            "queryOnlyOnOff": false,
            "commandOnlyOnOff": false,
            "commandOnlyTemperatureControl": false,
            "queryOnlyTemperatureControl": false,
            "foodPresets": [
              {
                "food_preset_name": "PIZZA",
                "supported_units": ["UNKNOWN_UNITS", "NO_UNITS"],
                "food_synonyms": [
                  {
                    "synonym": [
                      "Pizza",
                      "Za",
                      "Pie",
                      "Tomato Pie",
                    ],
                    "lang": "en",
                  },
                ],
              },
              {
                "food_preset_name": "BAGEL",
                "supported_units": ["UNKNOWN_UNITS", "NO_UNITS"],
                "food_synonyms": [
                  {
                    "synonym": [
                      "Bagel",
                      "Doughnut",
                    ],
                    "lang": "en",
                  },
                ],

              },
            ],
            "supportedCookingModes": [
              "BAKE",
              "FRY",
              "ROAST",
              "BROIL",
              "WARM",
            ],
            "temperatureRange": {
              "minThresholdCelsius": 65,
              "maxThresholdCelsius": 230,
            },
            "temperatureStepCelsius": 5,
            "temperatureUnitForUX": "C",
            "commandOnlyTimer": false,
            "maxTimerLimitSec": 157784760,
          },
      );
    });
  });

  describe("Test metadata returns expected", function() {
    it("Should return the toaster metadata", function() {
      expect(testToaster.metadata).to.deep.equal(
          {
            "id": "testToaster",
            "type": "action.devices.types.OVEN",
            "traits": [
              "action.devices.traits.Cook",
              "action.devices.traits.OnOff",
              "action.devices.traits.TemperatureControl",
              "action.devices.traits.Timer",
            ],
            "name": {
              "name": "Test Toaster",
            },
            "willReportState": true,
            "attributes": {
              "queryOnlyOnOff": false,
              "commandOnlyOnOff": false,
              "foodPresets": [
                {
                  "food_preset_name": "PIZZA",
                  "supported_units": ["UNKNOWN_UNITS", "NO_UNITS"],
                  "food_synonyms": [
                    {
                      "synonym": [
                        "Pizza",
                        "Za",
                        "Pie",
                        "Tomato Pie",
                      ],
                      "lang": "en",
                    },
                  ],
                },
                {
                  "food_preset_name": "BAGEL",
                  "supported_units": ["UNKNOWN_UNITS", "NO_UNITS"],
                  "food_synonyms": [
                    {
                      "synonym": [
                        "Bagel",
                        "Doughnut",
                      ],
                      "lang": "en",
                    },
                  ],

                },
              ],
              "supportedCookingModes": [
                "BAKE",
                "FRY",
                "ROAST",
                "BROIL",
                "WARM",
              ],
              "commandOnlyTemperatureControl": false,
              "queryOnlyTemperatureControl": false,
              "temperatureRange": {
                "minThresholdCelsius": 65,
                "maxThresholdCelsius": 230,
              },
              "temperatureStepCelsius": 5,
              "temperatureUnitForUX": "C",
              "commandOnlyTimer": false,
              "maxTimerLimitSec": 157784760,
            },
          },
      );
    });
  });

  describe("Test reportState returns expected", function() {
    it("Should return the state of the toaster", function() {
      expect(testToaster.state).to.deep.equal(
          {
            "online": true,
            "on": false,
            "start": true,
            "currentCookingMode": "BAKE",
            "currentFoodPreset": "PIZZA",
            "currentFoodQuantity": 1,
            "currentFoodUnit": "NO_UNITS",
            "temperatureAmbientCelsius": undefined,
            "temperatureSetpointCelsius": undefined,
            "timerPaused": undefined,
            "timerRemainingSec": undefined,
          },
      );
    });
  });
});
