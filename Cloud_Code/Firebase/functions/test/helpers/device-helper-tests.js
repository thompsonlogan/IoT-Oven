import * as sinon from "sinon";
import { DocumentReference, DocumentSnapshot, Firestore } from "@google-cloud/firestore";
import chai from "chai";
import chaiAsPromised from "chai-as-promised";
import { DeviceHelper } from "../../helpers/device-helper.js";
import { FirestoreHelper } from "../../helpers/firestore-helper.js";

const expect = chai.expect;
chai.use(chaiAsPromised);

describe("FireStore Device Helper Tests", function() {
  describe("Test getDeviceWithProperties", function() {
    describe("Test getDeviceWithProperties returns single", function() {
      it("Should return a set containing one device of type toaster with properties", async function() {
        const firestoreStub = sinon.createStubInstance(FirestoreHelper);

        const devices = [
          {
            "id": "123",
          },
        ];

        const deviceData = {
          id: "123",
          type: "toaster",
          owner: "Test Owner",
          properties: {
            prop1: "foo",
            prop2: "bar",
          },
        };

        firestoreStub.getEndpointData.resolves(deviceData);

        const helper = new DeviceHelper(firestoreStub);
        const result = await helper.getDeviceWithProperties(devices);

        expect(Object.keys(result)).to.have.lengthOf(1, "More than one device returned");
        expect(result["123"].properties).to.deep.equal(deviceData.properties, "Device properties does not match");
        expect(result["123"].id).to.equal(deviceData.id, "Device id does not match");
        expect(result["123"].type).to.equal("action.devices.types.OVEN", "Device type is not OVEN");
        expect(result["123"].owner).to.equal(deviceData.owner, "Device owner does not match");
      });
    });

    describe("Test getDeviceWithProperties returns multiple", function() {
      it("Should return a set containing multiple devices of type toaster with properties", async function() {
        const firestoreStub = sinon.createStubInstance(FirestoreHelper);

        const devices = [
          {
            "id": "123",
          },
          {
            "id": "456",
          },
          {
            "id": "789",
          },
        ];

        const device1 = {
          id: "123",
          type: "toaster",
          owner: "Test Owner 1",
          properties: {
            prop1: "foo",
            prop2: "bar",
          },
        };
        const device2 = {
          id: "456",
          type: "toaster",
          owner: "Test Owner 2",
          properties: {
            prop1: "fizz",
            prop2: "buzz",
          },
        };
        const device3 = {
          id: "789",
          type: "toaster",
          owner: "Test Owner 1",
          properties: {
            prop1: "bar",
            prop2: "foo",
          },
        };

        firestoreStub.getEndpointData.withArgs("deviceProperties/123").resolves(device1);
        firestoreStub.getEndpointData.withArgs("deviceProperties/456").resolves(device2);
        firestoreStub.getEndpointData.withArgs("deviceProperties/789").resolves(device3);

        const helper = new DeviceHelper(firestoreStub);
        const result = await helper.getDeviceWithProperties(devices);

        expect(Object.keys(result)).to.have.lengthOf(3, "Incorrect Number of Devices Returned");
        [device1, device2, device3].forEach((device) => {
          expect(result[device.id].properties).to.deep.equal(device.properties, "Device properties does not match");
          expect(result[device.id].id).to.equal(device.id, "Device id does not match");
          expect(result[device.id].type).to.equal("action.devices.types.OVEN", "Device type is not OVEN");
          expect(result[device.id].owner).to.equal(device.owner, "Device owner does not match");
        });
      });
    });

    describe("Test getDeviceWithProperties returns error object", function() {
      it("Should contain and error when the document does not exist", async function() {
        const firestoreStub = sinon.createStubInstance(FirestoreHelper);

        const devices = [
          {
            "id": "123",
          },
        ];

        firestoreStub.getEndpointData.throws(new Error("Device not in database"));

        const helper = new DeviceHelper(firestoreStub);
        const result = await helper.getDeviceWithProperties(devices);
        expect(result["123"].message).to.deep.equal("Device not in database");
      });
    });
  });

  describe("Test getDeviceWithState", function() {
    describe("Test getDeviceWithState returns single", function() {
      it("Should return a set containing one device of type toaster with state", async function() {
        const firestoreStub = sinon.createStubInstance(FirestoreHelper);

        const devices = [
          {
            "id": "123",
          },
        ];

        const deviceData = {
          id: "123",
          type: "toaster",
          owner: "Test Owner",
          state: {
            prop1: "foo",
            prop2: "bar",
          },
        };

        firestoreStub.getEndpointData.resolves(deviceData);

        const helper = new DeviceHelper(firestoreStub);
        const result = await helper.getDevicesWithStates(devices);

        expect(Object.keys(result)).to.have.lengthOf(1, "More than one device returned");
        expect(result["123"].configs).to.deep.equal(deviceData.configs, "Device state does not match");
        expect(result["123"].id).to.equal(deviceData.id, "Device id does not match");
        expect(result["123"].type).to.equal("action.devices.types.OVEN", "Device type is not OVEN");
        expect(result["123"].owner).to.equal(deviceData.owner, "Device owner does not match");
      });
    });

    describe("Test getDeviceWithStates returns multiple", function() {
      it("Should return a set containing multiple devices of type toaster with states", async function() {
        const firestoreStub = sinon.createStubInstance(FirestoreHelper);
        const devices = [
          {
            "id": "123",
          },
          {
            "id": "456",
          },
          {
            "id": "789",
          },
        ];

        const device1 = {
          id: "123",
          type: "toaster",
          owner: "Test Owner 1",
          state: {
            prop1: "foo",
            prop2: "bar",
          },
        };

        const device2 = {
          id: "456",
          type: "toaster",
          owner: "Test Owner 2",
          state: {
            prop1: "fizz",
            prop2: "buzz",
          },
        };

        const device3 = {
          id: "789",
          type: "toaster",
          owner: "Test Owner 1",
          state: {
            prop1: "bar",
            prop2: "foo",
          },
        };

        firestoreStub.getEndpointData.withArgs("deviceState/123").resolves(device1);
        firestoreStub.getEndpointData.withArgs("deviceState/456").resolves(device2);
        firestoreStub.getEndpointData.withArgs("deviceState/789").resolves(device3);

        const helper = new DeviceHelper(firestoreStub);
        const result = await helper.getDevicesWithStates(devices);

        expect(Object.keys(result)).to.have.lengthOf(3, "Incorrect Number of Devices Returned");
        [device1, device2, device3].forEach((device) => {
          expect(result[device.id].configs).to.deep.equal(device.configs, "Device state does not match");
          expect(result[device.id].id).to.equal(device.id, "Device id does not match");
          expect(result[device.id].type).to.equal("action.devices.types.OVEN", "Device type is not OVEN");
          expect(result[device.id].owner).to.equal(device.owner, "Device owner does not match");
        });
      });
    });

    describe("Test getDeviceWithStates returns error object", function() {
      it("Should contain an error when the document does not exist", async function() {
        const firestoreStub = sinon.createStubInstance(FirestoreHelper);

        const devices = [
          {
            "id": "123",
          },
        ];

        firestoreStub.getEndpointData.throws(new Error("Device not in database"));

        const helper = new DeviceHelper(firestoreStub);
        const result = await helper.getDevicesWithStates(devices);
        expect(result["123"].message).to.deep.equal("Device not in database");
      });
    });
  });
});
