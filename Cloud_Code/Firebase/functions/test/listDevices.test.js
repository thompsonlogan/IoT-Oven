import { expect } from "chai";
import sinon from "sinon";
import { randomUUID } from "crypto";
import { Firestore, CollectionReference, Query, QuerySnapshot } from "@google-cloud/firestore";
import { listDeviceDocuments } from "../spectrumFunctions/listDevicesFunction.js";

const setupDocStub = (deviceName, ownerId) => {
  const deviceId = randomUUID();
  const data = {
    name: deviceName,
    type: "Toaster",
    owner: ownerId,
  };

  const doc = {
    id: deviceId,
    data: sinon.stub(),
  };
  doc.data.returns(data);

  return {
    deviceId: deviceId,
    document: doc,
    data: data,
  };
};

const setupUnitTests = (ownerId) => {
  const path = "path";

  const firestoreStub = sinon.createStubInstance(Firestore);
  const collectionStub = sinon.createStubInstance(CollectionReference);
  const queryStub = sinon.createStubInstance(Query);
  const snapStub = sinon.createStubInstance(QuerySnapshot);

  firestoreStub.collection.withArgs(path).returns(collectionStub);
  collectionStub.where.withArgs('owner', '==', ownerId).returns(queryStub);
  queryStub.get.returns(snapStub);

  const ref = firestoreStub.collection(path);

  return {
    collectionRef: ref,
    snapStub: snapStub,
  };
};

describe("List devices unit tests", function() {
  describe("One device", function() {
    it("Should return the expected data", async function() {
      const ownerId = randomUUID();
      const { deviceId, document, data } = setupDocStub("Test device", ownerId);
      const { collectionRef, snapStub } = setupUnitTests(ownerId);
      sinon.stub(snapStub, "docs").value([document]);

      const list = await listDeviceDocuments(collectionRef, ownerId);

      expect(list, "Document list does not contain device id")
        .to.have.property(deviceId);

      expect(list[deviceId], `Document for device ${deviceId} does not have the right data`)
        .to.deep.equal(data);
    });
  });

  describe("Two devices", function() {
    it("Should return the expected data", async function() {
      const ownerId = randomUUID();
      const firstDevice = setupDocStub("Test device 1", ownerId);
      const secondDevice = setupDocStub("Test device 2", ownerId);
      const { collectionRef, snapStub } = setupUnitTests(ownerId);
      sinon.stub(snapStub, "docs").value([firstDevice.document, secondDevice.document]);

      const list = await listDeviceDocuments(collectionRef, ownerId);

      expect(list, "Document list does not contain first device id")
        .to.have.property(firstDevice.deviceId);

      expect(list, "Document list does not contain second device id")
        .to.have.property(secondDevice.deviceId);

      expect(list[firstDevice.deviceId], `Document for device ${firstDevice.deviceId} does not have the right data`)
        .to.deep.equal(firstDevice.data);

      expect(list[secondDevice.deviceId], `Document for device ${secondDevice.deviceId} does not have the right data`)
        .to.deep.equal(secondDevice.data);
    });
  });
});