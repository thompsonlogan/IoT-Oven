import { expect } from "chai";
import { firestore } from "../admin.js";
import registerDevice, { getDevicePath, getDevice, keyExistsInCreds } from "../spectrumFunctions/registerDeviceFunction.js";
import createDevice, { getKeys } from "../spectrumFunctions/createDeviceFunction.js";
import { getRegistryPath, getClient } from "../spectrumFunctions/iotClientHelper.js";
import { randomUUID } from "crypto";
import sinon from "sinon";

function setupWrongDeviceRegistration(ctx, data) {
  // Register device callable request
  return {
    data: {
      deviceId: data.deviceId ?? ctx.deviceData.deviceId,
      publicKey: data.publicKey ?? ctx.deviceData.publicKey,
      deviceName: ctx.deviceName,
    },
    context: {
      auth: {
        uid: data.ownerId ?? ctx.ownerId,
      },
    },
  };
}

function responseError() {
  return it("should fail", function() {
    const res = this.test.ctx.res;
    expect(res, "Registration did not error, or status was not 409").to.have.nested.property("httpErrorCode.status", 409);
  });
}

function wrongInformationIoTTest() {
  return describe("IoT Core Device", function() {
    before(async function() {
      const client = await getClient();
      const getDeviceRequest = {
        name: getDevicePath(getRegistryPath(), this.deviceData.deviceId),
        fieldMask: "credentials,blocked",
      };
      this.getDeviceResponse = await getDevice(client, getDeviceRequest);
    });

    it("should exist", function() {
      expect(this.test.ctx.getDeviceResponse, "Device does not exist?")
          .to.be.ok;
    });

    it("should be blocked", function() {
      expect(this.test.ctx.getDeviceResponse, "Device is not blocked")
          .to.not.have.nested.property("data.blocked", true);
    });
  });
}

function wrongInformationFirebaseTest() {
  return describe("Firestore device", function() {
    before(async function() {
      this.configDoc = await this.configRef.get();
      this.propertiesDoc = await this.propertiesRef.get();
      this.stateDoc = await this.stateRef.get();
      this.userDoc = await this.userRef.get();
    });

    describe("Config doc", function() {
      it("should not exist", function() {
        expect(this.test.ctx.configDoc.exists, "Config doc does exist")
            .to.be.false;
      });
    });

    describe("Properties doc", function() {
      it("should not exist", function() {
        expect(this.test.ctx.propertiesDoc.exists, "Properties doc does exist")
            .to.be.false;
      });
    });

    describe("State doc", function() {
      it("should not exist", function() {
        expect(this.test.ctx.stateDoc.exists, "State doc does exist")
            .to.be.false;
      });
    });

    describe("User doc", function() {
      it("should not exist", function() {
        expect(this.test.ctx.userDoc.exists, "User doc does exist")
            .to.be.false;
      });
    });
  });
}

describe("Register and create device integration tests", function() {
  before(function() {
    sinon.stub(console, "log");
    sinon.stub(console, "error");
  });

  after(function() {
    sinon.restore();
  });

  describe("Create then register integration", function() {
    before(async function() {
      // Create device
      this.createRes = {
        send: sinon.stub(),
        status: sinon.stub(),
      };
      this.createRes.send.callsFake((msg) => {
        this.deviceData = msg;
        return this.createRes;
      });
      this.createRes.status.returns(this.createRes);
      await createDevice({}, this.createRes);
    });

    after(async function() {
      // delete device from IoT Core
      const client = await getClient();
      const deleteReq = {
        name: getDevicePath(getRegistryPath(), this.deviceData.deviceId),
      };
      client.projects.locations.registries.devices.delete(deleteReq);
    });

    describe("Register with correct information", function() {
      before(async function() {
        this.ownerId = randomUUID();
        this.deviceName = "Test device name";

        // Create owner's user doc
        this.userRef = firestore.doc(`users/${this.ownerId}`);

        // Register device
        const data = {
          deviceId: this.deviceData.deviceId,
          publicKey: this.deviceData.publicKey,
          deviceName: this.deviceName,
        };
        const context = {
          auth: {
            uid: this.ownerId,
          },
        };
        try {
          this.registerRes = await registerDevice.run(data, context);
        } catch (error) {
          this.registerRes = error;
        }

        // setup document references
        this.configRef = firestore.doc(`deviceConfiguration/${this.deviceData.deviceId}`);
        this.propertiesRef = firestore.doc(`deviceProperties/${this.deviceData.deviceId}`);
        this.stateRef = firestore.doc(`deviceState/${this.deviceData.deviceId}`);
      });

      after(async function() {
        // delete config, properties, and state devices
        const batch = firestore.batch();
        batch.delete(this.userRef);
        batch.delete(this.configRef);
        batch.delete(this.propertiesRef);
        batch.delete(this.stateRef);
        await batch.commit();
      });

      describe("IoT Core Device", function() {
        before(async function() {
          const client = await getClient();
          const getDeviceRequest = {
            name: getDevicePath(getRegistryPath(), this.deviceData.deviceId),
            fieldMask: "credentials,blocked",
          };
          this.getDeviceResponse = await getDevice(client, getDeviceRequest);
        });

        it("should exist", function() {
          expect(this.test.ctx.getDeviceResponse, "Device does not exist?")
              .to.be.ok;
        });

        it("should not be blocked", function() {
          expect(this.test.ctx.getDeviceResponse, "Device is blocked")
              .to.not.have.nested.property("data.blocked");
        });

        it("should have matching public key", function() {
          const deviceCreds = this.test.ctx.getDeviceResponse.data.credentials;
          const publicKey = this.test.ctx.deviceData.publicKey;
          const keyExists = keyExistsInCreds(deviceCreds, publicKey);
          expect(keyExists, "The device does not have the expected public key")
              .to.be.true;
        });
      });

      describe("Firestore device", function() {
        before(async function() {
          this.configDoc = await this.configRef.get();
          this.propertiesDoc = await this.propertiesRef.get();
          this.stateDoc = await this.stateRef.get();
        });

        describe("Config doc", function() {
          it("should exist", function() {
            expect(this.test.ctx.configDoc.exists, "Config doc does not exist")
                .to.be.true;
          });

          it("should have the right owner ID", function() {
            const expectedId = this.test.ctx.ownerId;
            const realId = this.test.ctx.configDoc.data().owner;
            expect(expectedId, "Owner IDs do not match")
                .to.equal(realId);
          });
        });

        describe("Properties doc", function() {
          it("should exist", function() {
            expect(this.test.ctx.propertiesDoc.exists, "Properties doc does not exist")
                .to.be.true;
          });

          it("should have the right owner ID", function() {
            const expectedId = this.test.ctx.ownerId;
            const realId = this.test.ctx.propertiesDoc.data().owner;
            expect(expectedId, "Owner IDs do not match")
                .to.equal(realId);
          });
        });

        describe("State doc", function() {
          it("should exist", function() {
            expect(this.test.ctx.stateDoc.exists, "State doc does not exist")
                .to.be.true;
          });

          it("should have the right owner ID", function() {
            const expectedId = this.test.ctx.ownerId;
            const realId = this.test.ctx.stateDoc.data().owner;
            expect(expectedId, "Owner IDs do not match")
                .to.equal(realId);
          });
        });

        describe("Registration", function() {
          it("should not have failed", function() {
            expect(this.test.ctx.registerRes, "Registration failed")
                .to.not.have.property("code");
          });
        });

        describe("User document", function() {
          it("should exist", async function() {
            const userDoc = await this.test.ctx.userRef.get();
            expect(userDoc.exists, "User document does not exist")
                .to.be.true;
          });
        });
      });
    });

    describe("register with wrong information", function() {
      before(async function() {
        this.ownerId = randomUUID();
        this.deviceName = "Test device name";

        // Create owner's user doc
        this.userRef = firestore.doc(`users/${this.ownerId}`);

        // setup document references
        this.configRef = firestore.doc(`deviceConfiguration/${this.deviceData.deviceId}`);
        this.propertiesRef = firestore.doc(`deviceProperties/${this.deviceData.deviceId}`);
        this.stateRef = firestore.doc(`deviceState/${this.deviceData.deviceId}`);
      });

      afterEach(async function() {
        // delete config, properties, and state ref
        const batch = firestore.batch();
        batch.delete(this.configRef);
        batch.delete(this.propertiesRef);
        batch.delete(this.stateRef);
        await batch.commit();
      });

      after(async function() {
        // delete user ref after all testing is done
        await this.userRef.delete();
      });

      describe("Wrong device ID", function() {
        before(async function() {
          const { data, context } = setupWrongDeviceRegistration(this, {
            deviceId: `id-${randomUUID()}`,
          });

          try {
            this.res = await registerDevice.run(data, context);
          } catch (error) {
            this.res = error;
          }
        });

        describe("Response error", responseError);
        describe("Wrong information in firebase", wrongInformationFirebaseTest);
        describe("wrong information in IoT Core", wrongInformationIoTTest);
      });

      describe("wrong public key", function() {
        before(async function() {
          const { data, context } = setupWrongDeviceRegistration(this, {
            publicKey: getKeys().public,
          });

          try {
            this.res = await registerDevice.run(data, context);
          } catch (error) {
            this.res = error;
          }
        });

        describe("Response error", responseError);
        describe("Wrong information in firebase", wrongInformationFirebaseTest);
        describe("wrong information in IoT Core", wrongInformationIoTTest);
      });
    });
  });

  describe("Register device integration with empty properties", function() {
    it("Does not have a device ID", async function() {
      const data = {
        // deviceId: "id-test-device-0001",
        publicKey: "-----BEGIN PUBLIC KEY-----\nsome45data\n-----END PUBLIC KEY-----",
        deviceName: "Test device name",
      };

      const context = {
        auth: {
          uid: "test1001",
        },
      };

      let res = null;
      try {
        res = await registerDevice.run(data, context);
      } catch (error) {
        res = error;
      }

      expect(res, "Registration did not error, or status was not 409").to.have.nested.property("httpErrorCode.status", 409);
    });

    it("does not have owner ID", async function() {
      const data = {
        deviceId: "id-test-device-0001",
        publicKey: "-----BEGIN PUBLIC KEY-----\nsome45data\n-----END PUBLIC KEY-----",
        deviceName: "Test device name",
      };

      const context = {
        auth: {
          // uid: "test1001",
        },
      };

      let res = null;
      try {
        res = await registerDevice.run(data, context);
      } catch (error) {
        res = error;
      }

      expect(res, "Registration did not error, or status was not 409").to.have.nested.property("httpErrorCode.status", 409);
    });

    it("does not have public key", async function() {
      const data = {
        deviceId: "id-test-device-0001",
        // publicKey: "-----BEGIN PUBLIC KEY-----\nsome45data\n-----END PUBLIC KEY-----",
        deviceName: "Test device name",
      };

      const context = {
        auth: {
          uid: "test1001",
        },
      };

      let res = null;
      try {
        res = await registerDevice.run(data, context);
      } catch (error) {
        res = error;
      }

      expect(res, "Registration did not error, or status was not 409").to.have.nested.property("httpErrorCode.status", 409);
    });

    it("does not have device name", async function() {
      const data = {
        deviceId: "id-test-device-0001",
        publicKey: "-----BEGIN PUBLIC KEY-----\nsome45data\n-----END PUBLIC KEY-----",
        // deviceName: "Test device name",
      };

      const context = {
        auth: {
          uid: "test1001",
        },
      };

      let res = null;
      try {
        res = await registerDevice.run(data, context);
      } catch (error) {
        res = error;
      }

      expect(res, "Registration did not error, or status was not 409").to.have.nested.property("httpErrorCode.status", 409);
    });
  });
});
