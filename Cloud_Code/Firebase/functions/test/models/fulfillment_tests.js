import Sinon, * as sinon from "sinon";
import { FulfillmentController } from "../../controllers/fulfillment-controller.js";
import Toaster from "../../models/devices/toaster.js";
import { DeviceHelper } from "../../helpers/device-helper.js";
import { expect } from "chai";
import { FirestoreHelper } from "../../helpers/firestore-helper.js";

describe("fulfillment", function() {
  describe("OnQuerySuccess", function() {
    it("Should return the Query response", async function() {
      const deviceHelper = sinon.createStubInstance(DeviceHelper);
      const testFulfillment = new FulfillmentController(deviceHelper);
      const state = {
        "on": false,
        "currentCookingMode": "BAKE",
        "start": true,
        "temperatureSetpointCelsius": 200,
      };
      const properties = {
        "name": "Test Toaster",
      };
      const testToaster = new Toaster("testToaster", { "owner": "Test Owner", "state": state, "properties": properties, "online": true });

      deviceHelper.getDevicesWithStates.returns({ "testToaster": testToaster });

      const bodyRequest = {
        "requestId": "ff36a3cc-ec34-11e6-b1a0-64510650abcf",
        "inputs": [{
          "intent": "action.devices.QUERY",
          "payload": {
            "devices": [{
              "id": "testToaster",
            }],
          },
        }],
      };
      // credentialsStub = sinon.createStubInstance()
      const ourResponse = await testFulfillment.onQuery(bodyRequest);
      expect(ourResponse).to.deep.equal({
        "requestId": "ff36a3cc-ec34-11e6-b1a0-64510650abcf",
        "payload": {
          "devices": {
            "testToaster": {
              "on": false,
              "online": true,
              "start": true,
              "currentCookingMode": "BAKE",
              "currentFoodPreset": undefined,
              "currentFoodQuantity": undefined,
              "currentFoodUnit": undefined,
              "temperatureSetpointCelsius": 200,
              "temperatureAmbientCelsius": undefined,
              "timerPaused": undefined,
              "timerRemainingSec": undefined,
            },
          },
        },
      });
    });
  });

  describe("OnQuerySuccessNonViableID", function() {
    it("Should return the Query response", async function() {
      const deviceHelper = sinon.createStubInstance(DeviceHelper);
      const testFulfillment = new FulfillmentController(deviceHelper);
      const state = {
        "on": false,
      };
      const properties = {
        "name": "Test Toaster",
      };
      const testToaster = new Toaster("testToaster", { "owner": "Test Owner", "state": state, "properties": properties, "online": true });

      deviceHelper.getDevicesWithStates.returns({ "testToaster": testToaster });

      const bodyRequest = {
        "requestId": "ff36a3cc-ec34-11e6-b1a0-64510650abcf",
        "inputs": [{
          "intent": "action.devices.QUERY",
          "payload": {
            "devices": [{
              "id": "testToasterFake",
            }],
          },
        }],
      };
      // credentialsStub = sinon.createStubInstance()
      const ourResponse = await testFulfillment.onQuery(bodyRequest);
      expect(ourResponse).to.deep.equal({
        "requestId": "ff36a3cc-ec34-11e6-b1a0-64510650abcf",
        "payload": {
          "devices": {
          },
        },
      });
    });
  });

  describe("OnQuerySuccessTwoItems", function() {
    it("Should return the Query response", async function() {
      const deviceHelper = sinon.createStubInstance(DeviceHelper);
      const testFulfillment = new FulfillmentController(deviceHelper);
      const state = {
        "on": false,
        "currentCookingMode": "BAKE",
        "start": true,
        "temperatureSetpointCelsius": 200,
      };
      const properties = {
        "name": "Test Toaster",
      };
      const testToaster1 = new Toaster("testToaster1", { "owner": "Test Owner", "state": state, "properties": properties, "online": true });
      const testToaster2 = new Toaster("testToaster2", { "owner": "Test Owner", "state": state, "properties": properties, "online": true });

      deviceHelper.getDevicesWithStates.returns({ "testToaster1": testToaster1, "testToaster2": testToaster2 });

      const bodyRequest = {
        "requestId": "ff36a3cc-ec34-11e6-b1a0-64510650abcf",
        "inputs": [{
          "intent": "action.devices.QUERY",
          "payload": {
            "devices": [{
              "id": "testToaster1",
            },
            {
              "id": "testToaster2",
            }],
          },
        }],
      };
      // credentialsStub = sinon.createStubInstance()
      const ourResponse = await testFulfillment.onQuery(bodyRequest);
      expect(ourResponse).to.deep.equal({
        "requestId": "ff36a3cc-ec34-11e6-b1a0-64510650abcf",
        "payload": {
          "devices": {
            "testToaster1": {
              "on": false,
              "online": true,
              "start": true,
              "currentCookingMode": "BAKE",
              "currentFoodPreset": undefined,
              "currentFoodQuantity": undefined,
              "currentFoodUnit": undefined,
              "temperatureSetpointCelsius": 200,
              "temperatureAmbientCelsius": undefined,
              "timerPaused": undefined,
              "timerRemainingSec": undefined,
            },
            "testToaster2": {
              "on": false,
              "online": true,
              "start": true,
              "currentCookingMode": "BAKE",
              "currentFoodPreset": undefined,
              "currentFoodQuantity": undefined,
              "currentFoodUnit": undefined,
              "temperatureSetpointCelsius": 200,
              "temperatureAmbientCelsius": undefined,
              "timerPaused": undefined,
              "timerRemainingSec": undefined,
            },
          },
        },
      });
    });
  });

  describe("OnQuerySuccessNoItems", function() {
    it("Should return the Query response", async function() {
      const deviceHelper = sinon.createStubInstance(DeviceHelper);
      const testFulfillment = new FulfillmentController(deviceHelper);
      const state = {
        "on": false,
      };
      const properties = {
        "name": "Test Toaster",
      };

      // deviceHelper.getDevicesWithStates.returns({});

      const bodyRequest = {
        "requestId": "ff36a3cc-ec34-11e6-b1a0-64510650abcf",
        "inputs": [{
          "intent": "action.devices.QUERY",
          "payload": {
            "devices": [{
            }],
          },
        }],
      };
      // credentialsStub = sinon.createStubInstance()
      const ourResponse = await testFulfillment.onQuery(bodyRequest);
      expect(ourResponse).to.deep.equal({
        "requestId": "ff36a3cc-ec34-11e6-b1a0-64510650abcf",
        "payload": {
          "devices": {
          },
        },
      });
    });
  });


  describe("OnSyncSuccess", function() {
    it("Should return the Sync response", async function() {
      const deviceHelper = sinon.createStubInstance(DeviceHelper);
      const testFulfillment = new FulfillmentController(deviceHelper);
      const state = {
        "on": false,
      };
      const properties = {
        "name": "Test Toaster",
      };
      const testToaster = new Toaster("testToaster", { "owner": "Test Owner", "state": state, "properties": properties, "online": true });

      deviceHelper.getDevicesWithStates.returns({ "testToaster": testToaster });
      deviceHelper.getAllRegisteredDevices.returns([testToaster.metadata]);
      const userId = "1836.15267389";

      const bodyRequest = {
        "requestId": "ff36a3cc-ec34-11e6-b1a0-64510650abcf",
        "inputs": [{
          "intent": "action.devices.SYNC",
        }],
      };

      const ourResponse = await testFulfillment.onSync(bodyRequest, userId);
      expect(ourResponse).to.deep.equal({
        "requestId": "ff36a3cc-ec34-11e6-b1a0-64510650abcf",
        "payload": {
          "agentUserId": "1836.15267389",
          "devices":
            [
              {
                "attributes": {
                  "commandOnlyOnOff": false,
                  "queryOnlyOnOff": false,
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
                  "commandOnlyTemperatureControl": false,
                  "queryOnlyTemperatureControl": false,
                  "commandOnlyTimer": false,
                  "maxTimerLimitSec": 157784760,
                },
                "id": "testToaster",
                "name": {
                  "name": "Test Toaster",
                },
                "type": "action.devices.types.OVEN",
                "traits": [
                  "action.devices.traits.Cook",
                  "action.devices.traits.OnOff",
                  "action.devices.traits.TemperatureControl",
                  "action.devices.traits.Timer",
                ],
                "willReportState": true,
              },
            ],
        },
      });
    });
  });

  describe("OnSyncSuccessTwoItems", function() {
    it("Should return the Sync response", async function() {
      const deviceHelper = sinon.createStubInstance(DeviceHelper);
      const testFulfillment = new FulfillmentController(deviceHelper);
      const state = {
        "on": false,
      };
      const properties = {
        "name": "Test Toaster",
      };
      const testToaster1 = new Toaster("testToaster1", { "owner": "Test Owner", "state": state, "properties": properties, "online": true });
      const testToaster2 = new Toaster("testToaster2", { "owner": "Test Owner", "state": state, "properties": properties, "online": true });

      deviceHelper.getDevicesWithStates.returns({ "testToaster1": testToaster1, "testToaster2": testToaster2 });
      deviceHelper.getAllRegisteredDevices.returns([testToaster1.metadata, testToaster2.metadata]);
      const userId = "1836.15267389";

      const bodyRequest = {
        "requestId": "ff36a3cc-ec34-11e6-b1a0-64510650abcf",
        "inputs": [{
          "intent": "action.devices.SYNC",
        }],
      };

      const ourResponse = await testFulfillment.onSync(bodyRequest, userId);
      expect(ourResponse).to.deep.equal({
        "requestId": "ff36a3cc-ec34-11e6-b1a0-64510650abcf",
        "payload": {
          "agentUserId": "1836.15267389",
          "devices":
            [
              {
                "attributes": {
                  "commandOnlyOnOff": false,
                  "queryOnlyOnOff": false,
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
                  "commandOnlyTemperatureControl": false,
                  "queryOnlyTemperatureControl": false,
                  "commandOnlyTimer": false,
                  "maxTimerLimitSec": 157784760,
                },
                "id": "testToaster1",
                "name": {
                  "name": "Test Toaster",
                },
                "type": "action.devices.types.OVEN",
                "traits": [
                  "action.devices.traits.Cook",
                  "action.devices.traits.OnOff",
                  "action.devices.traits.TemperatureControl",
                  "action.devices.traits.Timer",
                ],
                "willReportState": true,
              },
              {
                "attributes": {
                  "commandOnlyOnOff": false,
                  "queryOnlyOnOff": false,
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
                  "commandOnlyTemperatureControl": false,
                  "queryOnlyTemperatureControl": false,
                  "commandOnlyTimer": false,
                  "maxTimerLimitSec": 157784760,
                },
                "id": "testToaster2",
                "name": {
                  "name": "Test Toaster",
                },
                "type": "action.devices.types.OVEN",
                "traits": [
                  "action.devices.traits.Cook",
                  "action.devices.traits.OnOff",
                  "action.devices.traits.TemperatureControl",
                  "action.devices.traits.Timer",
                ],
                "willReportState": true,
              },
            ],
        },
      });
    });
  });

  describe("OnSyncSuccessNoItems", function() {
    it("Should return the Sync response", async function() {
      const deviceHelper = sinon.createStubInstance(DeviceHelper);
      const testFulfillment = new FulfillmentController(deviceHelper);
      const state = {
        "on": false,
      };
      const properties = {
        "name": "Test Toaster",
      };
      const testToaster = new Toaster("testToaster", { "owner": "Test Owner", "state": state, "properties": properties, "online": true });

      // deviceHelper.getDevicesWithStates.returns({ "testToaster": testToaster });
      deviceHelper.getAllRegisteredDevices.returns([]);

      const userId = "1836.15267389";

      const bodyRequest = {
        "requestId": "ff36a3cc-ec34-11e6-b1a0-64510650abcf",
        "inputs": [{
          "intent": "action.devices.SYNC",
        }],
      };

      const ourResponse = await testFulfillment.onSync(bodyRequest, userId);
      expect(ourResponse).to.deep.equal({
        "requestId": "ff36a3cc-ec34-11e6-b1a0-64510650abcf",
        "payload": {
          "agentUserId": "1836.15267389",
          "devices": [],
        },
      });
    });
  });

  describe("OnExecuteSuccess", function() {
    it("Should return Execute response", async function() {
      const deviceHelper = sinon.createStubInstance(DeviceHelper);
      const firestoreHelper = sinon.createStubInstance(FirestoreHelper);
      const testFulfillment = new FulfillmentController(deviceHelper, firestoreHelper);
      const state = {
        "on": false,
      };
      const properties = {
        "name": "Test Toaster",
      };
      const testToaster1 = new Toaster("123", { "owner": "Test Owner", "state": state, "properties": properties, "online": true });

      deviceHelper.getDevicesWithStates.returns({ "123": testToaster1 });

      const bodyRequest = {
        "requestId": "ff36a3cc-ec34-11e6-b1a0-64510650abcf",
        "inputs": [{
          "intent": "action.devices.EXECUTE",
          "payload": {
            "commands": [{
              "devices": [{
                "id": "123",
                "customData": {
                  "on": false,
                  "online": true,
                },
              },
              ],
              "execution": [{
                "command": "action.devices.commands.OnOff",
                "params": {
                  "on": true,
                },
              }],
            }],
          },
        }],
      };
      const expectedResponse = {
        "requestId": "ff36a3cc-ec34-11e6-b1a0-64510650abcf",
        "payload": {
          "commands": [
            {
              "ids": [
                "123",
              ],
              "status": "PENDING",
              "states": {
                "on": true,
                "online": true,
              },
            },
          ],
        },
      };
      const variableResponse = await testFulfillment.onExecute(bodyRequest);
      expect(variableResponse).to.deep.equal(expectedResponse);
    });
  });

  describe("TestOnDisconnect", function() {
    it("Should return a successful Disconnect", async function() {
      const bodyRequest = {
        "requestId": "ff36a3cc-ec34-11e6-b1a0-64510650abcf",
        "inputs": [{
          "intent": "action.devices.DISCONNECT",
        }],
      };

      const firestoreStub = sinon.createStubInstance(FirestoreHelper);

      const devices = [
        {
          "id": "123",
        },
      ];

      const deviceData = {
        id: "123",
        type: "Toaster",
        owner: "Test Owner",
        properties: {
          prop1: "foo",
          prop2: "bar",
        },
      };

      firestoreStub.getEndpointData.resolves(deviceData);

      const deviceHelper = sinon.createStubInstance(DeviceHelper);
      const testFulfillment = new FulfillmentController(deviceHelper, firestoreStub);
      const ourResponse = await testFulfillment.onDisconnect(bodyRequest);
      expect(ourResponse).to.deep.equal({
      });
    });
  });

  describe("TestOnDisconnectSuccess", function() { });

  describe("TestOnDisconnectFailure", function() { });

  describe("TestOnExecuteMultipleToastersSuccess", function() {
    it("Should return Execute response", async function() {
      const deviceHelper = sinon.createStubInstance(DeviceHelper);
      const firestoreHelper = sinon.createStubInstance(FirestoreHelper);
      const testFulfillment = new FulfillmentController(deviceHelper, firestoreHelper);

      const Toaster1State = {
        "on": false,
      };

      const Toaster2State = {
        "on": false,
      };

      const testToaster1 = new Toaster("123", { "owner": "Test Owner", "state": Toaster1State, "online": true });

      const testToaster2 = new Toaster("456", { "owner": "Test Owner", "state": Toaster2State, "online": true });

      deviceHelper.getDevicesWithStates.returns({ "123": testToaster1, "456": testToaster2 });

      const bodyRequest = {
        "requestId": "ff36a3cc-ec34-11e6-b1a0-64510650abcf",
        "inputs": [{
          "intent": "action.devices.EXECUTE",
          "payload": {
            "commands": [{
              "devices": [{
                "id": "testToaster1",
              }, {
                "id": "testToaster2",
              }],
              "execution": [{
                "command": "action.devices.commands.OnOff",
                "params": {
                  "on": true,
                },
              }],
            }],
          },
        }],
      };
      const expectedResponse = {
        "requestId": "ff36a3cc-ec34-11e6-b1a0-64510650abcf",
        "payload": {
          "commands": [
            {
              "ids": [
                "123", "456",
              ],
              "status": "PENDING",
              "states": {
                "on": true,
                "online": true,
              },
            },
          ],
        },
      };
      const variableResponse = await testFulfillment.onExecute(bodyRequest);
      expect(variableResponse).to.deep.equal(expectedResponse);
    });
  });

  describe("TestOnExecuteOneToastersSuccess", function() {
    it("Should return Execute response", async function() {
      const deviceHelper = sinon.createStubInstance(DeviceHelper);
      const firestoreHelper = sinon.createStubInstance(FirestoreHelper);
      const testFulfillment = new FulfillmentController(deviceHelper, firestoreHelper);

      const ToasterState = {
        "on": false,
      };

      const testToaster = new Toaster("123", { "owner": "Test Owner", "state": ToasterState, "online": true });


      deviceHelper.getDevicesWithStates.returns({ "123": testToaster });

      const bodyRequest = {
        "requestId": "ff36a3cc-ec34-11e6-b1a0-64510650abcf",
        "inputs": [{
          "intent": "action.devices.EXECUTE",
          "payload": {
            "commands": [{
              "devices": [{
                "id": "testToaster",
              }],
              "execution": [{
                "command": "action.devices.commands.OnOff",
                "params": {
                  "on": true,
                },
              }],
            }],
          },
        }],
      };
      const expectedResponse = {
        "requestId": "ff36a3cc-ec34-11e6-b1a0-64510650abcf",
        "payload": {
          "commands": [
            {
              "ids": [
                "123",
              ],
              "status": "PENDING",
              "states": {
                "on": true,
                "online": true,
              },
            },
          ],
        },
      };
      const variableResponse = await testFulfillment.onExecute(bodyRequest);
      expect(variableResponse).to.deep.equal(expectedResponse);
    });
  });

  describe("TestOnExecuteInvalidToasterFailure", function() {
    it("Should return Error response", async function() {
      const deviceHelper = sinon.createStubInstance(DeviceHelper);
      const firestoreHelper = sinon.createStubInstance(FirestoreHelper);
      const testFulfillment = new FulfillmentController(deviceHelper, firestoreHelper);

      deviceHelper.getDevicesWithStates.returns({ "123": new Error("deviceNotFound") });

      const bodyRequest = {
        "requestId": "ff36a3cc-ec34-11e6-b1a0-64510650abcf",
        "inputs": [{
          "intent": "action.devices.EXECUTE",
          "payload": {
            "commands": [{
              "devices": [{
                "id": "123",
              },
              ],
              "execution": [{
                "command": "action.devices.commands.OnOff",
                "params": {
                  "on": true,
                },
              }],
            }],
          },
        }],
      };
      const expectedResponse = {
        "requestId": "ff36a3cc-ec34-11e6-b1a0-64510650abcf",
        "payload": {
          "commands": [
            {
              "ids": [
                "123",
              ],
              "status": "ERROR",
              "errorCode": "deviceNotFound",
            },
          ],
        },
      };
      const variableResponse = await testFulfillment.onExecute(bodyRequest);
      expect(variableResponse).to.deep.equal(expectedResponse);
    });
  });

  describe("TestOnExecuteToastersInMultipleStates", function() {
    it("Should return both and error and pending response", async function() {
      const deviceHelper = sinon.createStubInstance(DeviceHelper);
      const firestoreHelper = sinon.createStubInstance(FirestoreHelper);
      const testFulfillment = new FulfillmentController(deviceHelper, firestoreHelper);

      const testToasterState = {
        "on": false,
      };

      const testToaster = new Toaster("123", { "owner": "Test Owner", "state": testToasterState, "online": true });

      deviceHelper.getDevicesWithStates.returns({ "123": new Error("deviceNotFound"), "456": testToaster });

      const bodyRequest = {
        "requestId": "ff36a3cc-ec34-11e6-b1a0-64510650abcf",
        "inputs": [{
          "intent": "action.devices.EXECUTE",
          "payload": {
            "commands": [{
              "devices": [{
                "id": "123",
              },
              {
                "id": "456",
              },
              ],
              "execution": [{
                "command": "action.devices.commands.OnOff",
                "params": {
                  "on": true,
                },
              }],
            }],
          },
        }],
      };
      const expectedResponse = {
        "requestId": "ff36a3cc-ec34-11e6-b1a0-64510650abcf",
        "payload": {
          "commands": [
            {
              "ids": [
                "123",
              ],
              "status": "ERROR",
              "errorCode": "deviceNotFound",
            },
            {
              "ids": [
                "456",
              ],
              "status": "PENDING",
              "states": {
                "on": true,
                "online": true,
              },
            },
          ],
        },
      };
      const variableResponse = await testFulfillment.onExecute(bodyRequest);
      expect(variableResponse).to.deep.equal(expectedResponse);
    });
  });
});
