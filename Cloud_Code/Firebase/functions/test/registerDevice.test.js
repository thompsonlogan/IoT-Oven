import { Firestore, DocumentReference, DocumentSnapshot, WriteBatch } from "@google-cloud/firestore";
import { expect } from "chai";
import sinon from "sinon";
import { getDevicePath, checkRefsDoExist, keyExistsInCreds, setupBatch } from "../spectrumFunctions/registerDeviceFunction.js";
import { getDeviceId, getKeys } from "../spectrumFunctions/createDeviceFunction.js";
import { getRegistryPath } from "../spectrumFunctions/iotClientHelper.js";

describe("Register device unit tests", function() {
  describe("Get device path", function() {
    it("should be {path}/devices/{deviceID}", function() {
      const registryPath = getRegistryPath();
      const id = getDeviceId();
      const devicePath = getDevicePath(registryPath, id);
      expect(devicePath, "Device path doesn't match")
          .to.equal(`${registryPath}/devices/${id}`);
    });
  });

  describe("Check refs do exist", function() {
    afterEach(function() {
      sinon.restore();
    });

    describe("One ref", function() {
      beforeEach(function() {
        const path1 = "path1/testDevice";

        const firestoreStub = sinon.createStubInstance(Firestore);
        const refStub1 = sinon.createStubInstance(DocumentReference);
        this.docStub1 = sinon.createStubInstance(DocumentSnapshot);

        firestoreStub.doc.withArgs(path1).returns(refStub1);
        refStub1.get.resolves(this.docStub1);

        this.ref1 = firestoreStub.doc(path1);
      });

      it("Should already exist", async function() {
        sinon.stub(this.test.ctx.docStub1, "exists").value(true);

        const doesExist = await checkRefsDoExist(this.test.ctx.ref1);

        expect(doesExist, "The ref does exist")
            .to.be.true;
      });

      it("Should not exist", async function() {
        sinon.stub(this.test.ctx.docStub1, "exists").value(false);

        const doesExist = await checkRefsDoExist(this.test.ctx.ref1);

        expect(doesExist, "The ref does not exist")
            .to.be.false;
      });
    });

    describe("Three refs", function() {
      beforeEach(function() {
        const path1 = "path1/testDevice";
        const path2 = "path2/testDevice";
        const path3 = "path3/testDevice";

        const firestoreStub = sinon.createStubInstance(Firestore);

        const refStub1 = sinon.createStubInstance(DocumentReference);
        this.docStub1 = sinon.createStubInstance(DocumentSnapshot);

        const refStub2 = sinon.createStubInstance(DocumentReference);
        this.docStub2 = sinon.createStubInstance(DocumentSnapshot);

        const refStub3 = sinon.createStubInstance(DocumentReference);
        this.docStub3 = sinon.createStubInstance(DocumentSnapshot);

        firestoreStub.doc.withArgs(path1).returns(refStub1);
        firestoreStub.doc.withArgs(path2).returns(refStub2);
        firestoreStub.doc.withArgs(path3).returns(refStub3);

        refStub1.get.resolves(this.docStub1);
        refStub2.get.resolves(this.docStub2);
        refStub3.get.resolves(this.docStub3);

        this.ref1 = firestoreStub.doc(path1);
        this.ref2 = firestoreStub.doc(path2);
        this.ref3 = firestoreStub.doc(path3);
      });

      it("none should exist", async function() {
        sinon.stub(this.test.ctx.docStub1, "exists").value(true);
        sinon.stub(this.test.ctx.docStub2, "exists").value(true);
        sinon.stub(this.test.ctx.docStub3, "exists").value(true);

        const doesExist = await checkRefsDoExist(this.test.ctx.ref1, this.test.ctx.ref2, this.test.ctx.ref3);

        expect(doesExist, "One ref does exist")
            .to.be.true;
      });

      it("one should exist", async function() {
        sinon.stub(this.test.ctx.docStub1, "exists").value(true);
        sinon.stub(this.test.ctx.docStub2, "exists").value(false);
        sinon.stub(this.test.ctx.docStub3, "exists").value(true);

        const doesExist = await checkRefsDoExist(this.test.ctx.ref1, this.test.ctx.ref2, this.test.ctx.ref3);

        expect(doesExist, "All refs exist")
            .to.be.true;
      });
    });
  });

  describe("Key exist in credentials", function() {
    before(function() {
      this.keys = [getKeys().public, getKeys().public, getKeys().public];
    });

    it("should have an existing key", function() {
      const keys = this.test.ctx.keys;
      const iotCreds = [
        {
          publicKey: {
            key: keys[0],
          },
        },
        {
          publicKey: {
            key: keys[1],
          },
        },
        {
          publicKey: {
            key: keys[2],
          },
        },
      ];
      const doesExist = keyExistsInCreds(iotCreds, keys[1]);
      expect(doesExist, "The key does not exist in the credentials")
          .to.be.true;
    });

    it("should have an existing key without newlines", function() {
      const keys = this.test.ctx.keys;
      const iotCreds = [
        {
          publicKey: {
            key: keys[0],
          },
        },
      ];

      const key = keys[0].replace(/\n/g, "");

      const doesExist = keyExistsInCreds(iotCreds, key);
      expect(doesExist, "The key does not exist in the credentials")
          .to.be.true;
    });

    it("should not have an existing key", function() {
      const keys = this.test.ctx.keys;
      const iotCreds = [
        {
          publicKey: {
            key: keys[0],
          },
        },
        {
          publicKey: {
            key: keys[1],
          },
        },
      ];
      const doesExist = keyExistsInCreds(iotCreds, keys[2]);
      expect(doesExist, "The key does exist in the credentials")
          .to.be.false;
    });

    it("has no keys", function() {
      const keys = this.test.ctx.keys;
      const iotCreds = [];
      const doesExist = keyExistsInCreds(iotCreds, keys[0]);
      expect(doesExist, "The key does exist in the empty credential list")
          .to.be.false;
    });
  });

  describe("Setup batch", function() {
    before(function() {
      this.path1 = "config/testDevice";
      this.path2 = "properties/testDevice";
      this.path3 = "state/testDevice";

      const firestoreStub = sinon.createStubInstance(Firestore);

      const refStub1 = sinon.createStubInstance(DocumentReference);
      sinon.stub(refStub1, "path").value(this.path1);
      this.docStub1 = sinon.createStubInstance(DocumentSnapshot);

      const refStub2 = sinon.createStubInstance(DocumentReference);
      sinon.stub(refStub2, "path").value(this.path2);
      this.docStub2 = sinon.createStubInstance(DocumentSnapshot);

      const refStub3 = sinon.createStubInstance(DocumentReference);
      sinon.stub(refStub3, "path").value(this.path3);
      this.docStub3 = sinon.createStubInstance(DocumentSnapshot);

      firestoreStub.doc.withArgs(this.path1).returns(refStub1);
      firestoreStub.doc.withArgs(this.path2).returns(refStub2);
      firestoreStub.doc.withArgs(this.path3).returns(refStub3);

      this.batchData = [];
      this.batchStub = sinon.createStubInstance(WriteBatch);
      this.batchStub.set.callsFake((ref, data) => {
        this.batchData.push({
          path: ref.path,
          data: data,
        });
        return this.batchStub;
      });

      refStub1.get.resolves(this.docStub1);
      refStub2.get.resolves(this.docStub2);
      refStub3.get.resolves(this.docStub3);

      this.refs = {
        config: firestoreStub.doc(this.path1),
        properties: firestoreStub.doc(this.path2),
        state: firestoreStub.doc(this.path3),
      };
      this.ownerId = "test1000";
      this.deviceName = "name of device";
      setupBatch(this.batchStub, this.refs, this.ownerId, this.deviceName);
    });

    it("should have three objects", function() {
      expect(this.test.ctx.batchData, "There are more/less than three objects in the batch data")
          .to.have.length(3);
    });

    describe("set", function() {
      it("should have been called three times", function() {
        this.test.ctx.batchStub.set.calledThrice;
      });

      it("should have been called with ref 1", function() {
        const refs = this.test.ctx.refs;
        this.test.ctx.batchStub.set.calledWith(refs.config);
      });

      it("should have been called with ref 2", function() {
        const refs = this.test.ctx.refs;
        this.test.ctx.batchStub.set.calledWith(refs.properties);
      });

      it("should have been called with ref 3", function() {
        const refs = this.test.ctx.refs;
        this.test.ctx.batchStub.set.calledWith(refs.state);
      });
    });

    describe("paths", function() {
      it("should all have a path", function() {
        const data = this.test.ctx.batchData.map((d) => d.path);
        const allHavePath = data.every((d) => d != null);
        expect(allHavePath, "One object does not have a path property")
            .to.be.true;
      });

      it("should have correct path 1", function() {
        const data = this.test.ctx.batchData.map((d) => ({ path: d.path }));
        expect(data, "Path 1 does not exist")
            .to.be.an("array").that.deep.includes({ path: this.test.ctx.path1 });
      });

      it("should have correct path 2", function() {
        const data = this.test.ctx.batchData.map((d) => ({ path: d.path }));
        expect(data, "Path 2 does not exist")
            .to.be.an("array").that.deep.includes({ path: this.test.ctx.path2 });
      });

      it("should have correct path 3", function() {
        const data = this.test.ctx.batchData.map((d) => ({ path: d.path }));
        expect(data, "Path 3 does not exist")
            .to.be.an("array").that.deep.includes({ path: this.test.ctx.path3 });
      });
    });

    describe("Data", function() {
      it("should all have the correct owner ID", function() {
        const data = this.test.ctx.batchData.map((d) => ({ owner: d.data.owner }));
        const allHaveOwner = data.every((d) => d.owner == this.test.ctx.ownerId);
        expect(allHaveOwner, "One object does not have the correct owner")
            .to.be.true;
      });

      it("should have type toaster", function() {
        const data = this.test.ctx.batchData.map((d) => ({ type: d.data.type }));
        expect(data, "The device type is not toaster")
            .to.be.an("array").that.deep.includes({ type: "toaster" });
      });

      it("should have the correct device name", function() {
        const data = this.test.ctx.batchData.map((d) => ({ properties: d.data.properties }));
        expect(data, "The device name is incorrect")
            .to.be.an("array").that.deep.includes({ properties: { name: this.test.ctx.deviceName } });
      });
    });
  });
});
