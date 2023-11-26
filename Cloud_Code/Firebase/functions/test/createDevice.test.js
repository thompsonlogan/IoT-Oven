import { expect } from "chai";
import { createSign, createVerify } from "crypto";
import { getDeviceId, getKeys, getDeviceCreateReq } from "../spectrumFunctions/createDeviceFunction.js";
import { getRegistryPath } from "../spectrumFunctions/iotClientHelper.js";

describe("Create device unit tests", function() {
  describe("Device ID", function() {
    it("should match the regular expression", function() {
      const deviceId = getDeviceId();
      expect(deviceId, "Device ID does not match the regular expression")
          .to.match(/^id(-[a-z0-9]{4,12}){5}$/);
    });
  });

  describe("Key Pairs", function() {
    before(function() {
      this.keyPair = getKeys();
    });

    it("should have a valid public key", function() {
      expect(this.test.ctx.keyPair, "The public key does not match the regular expression")
          .to.have.property("public")
          .with.match(/^-{5}BEGIN PUBLIC KEY-{5}\n*/)
          .and.match(/\n*-{5}END PUBLIC KEY-{5}\n*$/);
    });

    it("should have a valid private key", function() {
      expect(this.test.ctx.keyPair, "The private key does not match the regular expression")
          .to.have.property("private")
          .with.match(/^-{5}BEGIN EC PRIVATE KEY-{5}/)
          .and.match(/\n*-{5}END EC PRIVATE KEY-{5}\n*$/);
    });

    it("should match each other", function() {
      const privateKey = this.test.ctx.keyPair.private;
      const publicKey = this.test.ctx.keyPair.public;
      const algorithm = "SHA256";
      const data = "data to verify";
      const encoding = "hex";

      const sign = createSign(algorithm);
      sign.write(data);
      sign.end();

      const signature = sign.sign(privateKey, encoding);

      const verify = createVerify(algorithm);
      verify.write(data);
      verify.end();

      const verified = verify.verify(publicKey, signature, encoding);
      expect(verified, "Public and private key pairs were not verified")
          .to.be.true;
    });
  });

  describe("Device create request", function() {
    before(function() {
      this.deviceId = getDeviceId();
      this.keyPair = getKeys();
      this.deviceReq = getDeviceCreateReq(this.deviceId, this.keyPair.public);
    });

    it("should have a valid device path", function() {
      const req = this.test.ctx.deviceReq;
      expect(req, "The device path either does not exist or is invalid")
          .to.have.property("parent", getRegistryPath());
    });

    it("should have the same device ID", function() {
      const req = this.test.ctx.deviceReq;
      expect(req, "The device id either does not or match")
          .to.have.nested.property("requestBody.id", this.test.ctx.deviceId);
    });

    describe("credentials", function() {
      it("should have the correct credentials format", function() {
        const req = this.test.ctx.deviceReq;
        expect(req, "The credential format either does not exist or match")
            .to.have.nested.property("requestBody.credentials.publicKey.format", "ES256_PEM",
            );
      });

      it("should have valid credentials", function() {
        const req = this.test.ctx.deviceReq;
        const publicKey = this.test.ctx.keyPair.public;
        expect(req, "The public key either does not exist or match")
            .to.have.nested.property("requestBody.credentials.publicKey.key", publicKey,
            );
      });
    });

    it("should be blocked", function() {
      const req = this.test.ctx.deviceReq;
      expect(req, "The blocked property either does not exist or is false")
          .to.have.nested.property("requestBody.blocked", true);
    });
  });
});
