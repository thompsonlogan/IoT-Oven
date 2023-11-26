import { expect } from "chai";
import { getRegistryPath } from "../spectrumFunctions/iotClientHelper.js";

describe("IoT client helper unit tests", function() {
  describe("Registry Path", function() {
    it("should match expected value", function() {
      const path = getRegistryPath();
      expect(path, "Registry path does not match expected value")
          .to.equal("projects/spectrum-brands-main-project/locations/us-central1/registries/ToasterOven");
    });
  });
});
