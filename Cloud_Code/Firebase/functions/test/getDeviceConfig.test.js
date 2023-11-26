import { expect } from "chai";
import { firestore } from "../admin.js";
import { randomUUID } from "crypto";
import sinon from "sinon";
import getDeviceConfig from "../spectrumFunctions/getDeviceConfigFunction.js";

describe("Get device config integration tests", function() {
  before(async function() {
    sinon.stub(console, "log");
    sinon.stub(console, "error");

    this.deviceId = randomUUID();
    this.ownerId = randomUUID();

    this.configData = {
      owner: this.ownerId,
      config: {
        targetTemperature: 400,
      },
    };

    this.configDoc = firestore.doc(`deviceConfiguration/${this.deviceId}`);
    await this.configDoc.set(this.configData);
  });

  after(async function() {
    await this.configDoc.delete();

    sinon.restore();
  });

  describe("With an actual (fake) device", function() {
    it("should match the expected data", async function() {
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
        res = await getDeviceConfig.run(data, context);
      } catch (error) {
        res = error;
      }

      expect(res, "Registration did error, and status was 409").to.not.have.nested.property("httpErrorCode.status", 409);

      expect(res, "Device state data does not match").to.deep.equal(this.test.ctx.configData);
    });
  });

  describe("As the incorrect owner", function() {
    it("should return with an error", async function() {
      const data = {
        deviceId: this.test.ctx.deviceId,
      };
      const context = {
        auth: {
          uid: "different-" + this.test.ctx.ownerId,
        },
      };

      let res = null;
      try {
        res = await getDeviceConfig.run(data, context);
      } catch (error) {
        res = error;
      }

      expect(res, "Registration did not error, or status was not 409").to.have.nested.property("httpErrorCode.status", 409);
    });
  });

  describe("Without a device", function() {
    it("Should return with an error", async function() {
      const data = {
        deviceId: "different-" + this.test.ctx.deviceId,
      };
      const context = {
        auth: {
          uid: this.test.ctx.ownerId,
        },
      };

      let res = null;
      try {
        res = await getDeviceConfig.run(data, context);
      } catch (error) {
        res = error;
      }

      expect(res, "Registration did not error, or status was not 409").to.have.nested.property("httpErrorCode.status", 409);
    });
  });
});
