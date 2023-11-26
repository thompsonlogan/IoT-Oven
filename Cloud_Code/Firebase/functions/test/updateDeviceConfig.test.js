import { Firestore, DocumentReference, DocumentSnapshot, WriteBatch } from "@google-cloud/firestore";
import { expect } from "chai";
import { firestore } from "../admin.js";
import { randomUUID } from "crypto";
import sinon from "sinon";
import updateDeviceConfig, { updateDocument } from "../spectrumFunctions/updateDeviceConfigFunction.js";

const setupUnitTests = async (docExists) => {
  const deviceId = "testDevice";
  const ownerId = "testOwner";
  const path = `path/${deviceId}`;

  const firestoreStub = sinon.createStubInstance(Firestore);
  const refStub = sinon.createStubInstance(DocumentReference);
  const docStub = sinon.createStubInstance(DocumentSnapshot);

  firestoreStub.doc.withArgs(path).returns(refStub);
  refStub.get.resolves(docStub);

  const updateParameters = [];
  refStub.update.callsFake((path, data) => {
    updateParameters.push({
      fieldPath: path,
      updateData: data,
    });
  });

  docStub.data.returns({
    owner: ownerId,
    config: {},
  });
  sinon.stub(docStub, "exists").value(docExists);

  const ref = firestoreStub.doc(path);

  return {
    ref: ref,
    ownerId: ownerId,
    updateParameters: updateParameters,
  };
};

describe("Update device config tests", function() {
  before(function() {
    sinon.stub(console, "log");
    sinon.stub(console, "error");
  });

  after(function() {
    sinon.restore();
  });

  describe("Unit tests", function() {
    describe("Device document exists", function() {
      before(async function() {
        const { ref, ownerId, updateParameters } = await setupUnitTests(true);
        this.updateParameters = updateParameters;

        this.expectedData = {
          targetTemperature: 400,
          mode: "bake",
        };

        try {
          this.res = await updateDocument(ref, ownerId, this.expectedData);
        } catch (ex) {
          this.res = ex;
        }
      });

      it("should not throw an error", function() {
        expect(this.test.ctx.res, "Update document did not throw an error")
            .to.not.be.an("Error");
      });

      it("should only have one update parameter", function() {
        expect(this.test.ctx.updateParameters, "Update was not called only once")
            .to.have.lengthOf(1);
      });

      it("should have the right field path", function() {
        expect(this.test.ctx.updateParameters[0], "Update was not called with the right field path")
            .to.have.property("fieldPath", "config");
      });

      it("should have the right update data", function() {
        const expectedData = this.test.ctx.expectedData;
        expect(this.test.ctx.updateParameters[0], "Update was called with the wrong data")
            .to.have.property("updateData").that.deep.equals(expectedData);
      });
    });

    describe("Device document does not exist", function() {
      before(async function() {
        const { ref, ownerId, updateParameters } = await setupUnitTests(false);
        this.updateParameters = updateParameters;

        this.expectedData = {
          targetTemperature: 400,
          mode: "bake",
        };

        try {
          this.res = await updateDocument(ref, ownerId, this.expectedData);
        } catch (ex) {
          this.res = ex;
        }
      });

      it("should throw an error", function() {
        expect(this.test.ctx.res, "Update document did not throw an error")
            .to.be.an("Error");
      });

      it("should have no update parameters", function() {
        expect(this.test.ctx.updateParameters, "Update parameters was called")
            .to.have.lengthOf(0);
      });
    });

    describe("Wrong owner for the device", function() {
      before(async function() {
        const { ref, updateParameters } = await setupUnitTests(true);
        this.updateParameters = updateParameters;

        this.expectedData = {
          targetTemperature: 400,
          mode: "bake",
        };

        try {
          this.res = await updateDocument(ref, "different owner id", this.expectedData);
        } catch (ex) {
          this.res = ex;
        }
      });

      it("should throw an error", function() {
        expect(this.test.ctx.res, "Update document did not throw an error")
            .to.be.an("Error");
      });

      it("should have no update parameters", function() {
        expect(this.test.ctx.updateParameters, "Update parameters was called")
            .to.have.lengthOf(0);
      });
    });
  });

  describe("Integration tests", function() {
    describe("With an actual (fake) device", function() {
      before(async function() {
        this.deviceId = randomUUID();
        this.ownerId = randomUUID();

        this.configData = {
          owner: this.ownerId,
          config: {
            targetTemperature: 350,
            mode: "bake",
          },
        };

        this.configRef = firestore.doc(`deviceConfiguration/${this.deviceId}`);
        await this.configRef.set(this.configData);
      });

      after(async function() {
        await this.configRef.delete();
      });

      it("should match the expected data", async function() {
        const data = {
          deviceId: this.test.ctx.deviceId,
          config: {
            targetTemperature: 400,
            mode: "bake",
          },
        };
        const context = {
          auth: {
            uid: this.test.ctx.ownerId,
          },
        };

        let res = null;
        try {
          res = await updateDeviceConfig.run(data, context);
        } catch (error) {
          res = error;
        }

        expect(res, "Registration did error, and status was 409").to.not.have.nested.property("httpErrorCode.status", 409);

        const configDoc = await this.test.ctx.configRef.get();
        const configData = await configDoc.data();

        expect(configData, "config data does not have the config field")
            .to.have.property("config");

        expect(configData.config, "config data does not have the right temperature")
            .to.have.property("targetTemperature", 400);

        expect(configData.config, "config data does not have the right cooking mode")
            .to.have.property("mode", "bake");
      });
    });

    describe("Without a device", function() {
      before(function() {
        this.deviceId = randomUUID();
      });

      it("Should return with an error", async function() {
        const data = {
          deviceId: this.test.ctx.deviceId,
        };
        const context = {
          auth: {
            uid: this.test.ctx.ownerId,
          },
        };

        let res = null;
        try {
          res = await updateDeviceConfig.run(data, context);
        } catch (error) {
          res = error;
        }

        expect(res, "Registration did not error, or status was not 409").to.have.nested.property("httpErrorCode.status", 409);
      });
    });

    describe("With the wrong owner ID", function() {
      before(function() {
        this.ownerId = randomUUID();
      });

      it("Should return with an error", async function() {
        const data = {
          deviceId: this.test.ctx.deviceId,
        };
        const context = {
          auth: {
            uid: this.test.ctx.ownerId,
          },
        };

        let res = null;
        try {
          res = await updateDeviceConfig.run(data, context);
        } catch (error) {
          res = error;
        }

        expect(res, "Registration did not error, or status was not 409").to.have.nested.property("httpErrorCode.status", 409);
      });
    });
  });
});
