import { expect } from "chai";
import sinon from "sinon";
import { Firestore, DocumentReference, DocumentSnapshot } from "@google-cloud/firestore";
import { randomUUID } from "crypto";
import { firestore } from "../admin.js";
import { getDeviceDocument, getRefData } from "../spectrumFunctions/getDeviceDocumentHelper.js";

describe("Get device document helper unit tests", function() {
  before(function() {
    sinon.stub(console, "log");
    sinon.stub(console, "error");
  });

  after(function() {
    sinon.restore();
  });

  describe("getRefData", function() {
    before(function() {
      this.deviceId = "testDevice";
      this.ownerId = "owner-id";
      const path = `path/${this.deviceId}`;

      const firestoreStub = sinon.createStubInstance(Firestore);
      const refStub = sinon.createStubInstance(DocumentReference);
      this.docStub = sinon.createStubInstance(DocumentSnapshot);

      firestoreStub.doc.withArgs(path).returns(refStub);
      refStub.get.resolves(this.docStub);

      this.ref = firestoreStub.doc(path);
    });

    describe("With fake data", function() {
      it("Should return the expected data", async function() {
        const ownerId = this.test.ctx.ownerId;
        const expectedData = {
          owner: ownerId,
          data: {
            online: true,
            temperature: 400,
          },
        };
        this.test.ctx.docStub.data.returns(expectedData);
        sinon.stub(this.docStub, "exists").value(true);

        let res = null;
        try {
          res = await getRefData(this.test.ctx.deviceId, ownerId, this.test.ctx.ref);
        } catch (error) {
          res = error;
        }

        expect(res, "Registration threw an error").to.not.be.an("Error");

        expect(res, "Returned data does not match").to.deep.equal(expectedData);
      });
    });

    describe("As the wrong owner", function() {
      it("Should throw an exception", async function() {
        const ownerId = this.test.ctx.ownerId;
        const expectedData = {
          owner: ownerId,
          state: {
            online: true,
            temperature: 400,
          },
        };
        this.test.ctx.docStub.data.returns(expectedData);
        sinon.stub(this.docStub, "exists").value(true);

        let res = null;
        try {
          res = await getRefData(this.test.ctx.deviceId, "different-" + ownerId, this.test.ctx.ref);
        } catch (error) {
          res = error;
        }

        expect(res, "Registration did not throw an error").to.be.an("Error");
      });
    });

    describe("With a fake document that doesn't exist", function() {
      it("Should throw an exception", async function() {
        sinon.stub(this.docStub, "exists").value(false);

        let res = null;
        try {
          res = await getRefData(this.test.ctx.deviceId, this.test.ctx.ref);
        } catch (error) {
          res = error;
        }

        expect(res, "Registration did not throw an error").to.be.an("Error");
      });
    });
  });

  describe("getDeviceDocument", function() {
    describe("With an actual (fake) device document", function() {
      before(async function() {
        this.deviceId = randomUUID();
        this.ownerId = randomUUID();

        this.configData = {
          owner: this.ownerId,
          config: {
            targetTemperature: 400,
          },
        };

        this.collectionName = "someCollection";
        this.configDoc = firestore.doc(`${this.collectionName}/${this.deviceId}`);
        await this.configDoc.set(this.configData);
      });

      after(async function() {
        await this.configDoc.delete();
      });

      it("should return the expected data", async function() {
        let res = null;
        try {
          res = await getDeviceDocument(this.test.ctx.deviceId, this.test.ctx.ownerId, this.test.ctx.collectionName);
        } catch (error) {
          res = error;
        }

        expect(res, "Registration did error").to.not.be.an("Error");

        expect(res, "Device state data does not match").to.deep.equal(this.test.ctx.configData);
      });
    });

    describe("Without a device", function() {
      before(function() {
        this.deviceId = randomUUID();
        this.ownerId = randomUUID();
      });

      it("Should return with an error", async function() {
        let res = null;
        try {
          res = await getDeviceDocument(this.test.ctx.deviceId, this.test.ctx.ownerId, this.test.ctx.collectionName);
        } catch (error) {
          res = error;
        }

        expect(res, "Registration did not error").to.be.an("Error");
      });
    });
  });
});
