import { https } from "firebase-functions";
import { generateKeyPairSync, randomUUID } from "crypto";
import { getRegistryPath, getClient } from "./iotClientHelper.js";

const getDeviceId = () => {
  return "id-" + randomUUID();
};

const getKeys = () => {
  const { privateKey, publicKey } = generateKeyPairSync("ec", {
    namedCurve: "prime256v1",
    publicKeyEncoding: {
      format: "pem",
      type: "spki",
    },
    privateKeyEncoding: {
      type: "sec1",
      format: "pem",
    },
  });

  return {
    private: privateKey,
    public: publicKey,
  };
};

const getDeviceCreateReq = (deviceId, publicKey) => {
  return {
    parent: getRegistryPath(),
    requestBody: {
      id: deviceId,
      credentials: {
        publicKey: {
          format: "ES256_PEM",
          key: publicKey,
        },
      },
      blocked: true,
    },
  };
};

const createDevice = async (createReq) => {
  const client = await getClient();
  return await client.projects.locations.registries.devices.create(createReq);
};

// HTTP function createDevice
export default https.onRequest(async (_, res) => {
  // Device ID and Public/Private KeyPair
  const deviceId = getDeviceId();
  const keyPair = getKeys();

  // Request to create device
  const deviceCreateReq = getDeviceCreateReq(deviceId, keyPair.public);

  try {
    const createRs = await createDevice(deviceCreateReq);

    if (createRs) {
      const dev = {
        publicKey: keyPair.public,
        privateKey: keyPair.private,
        deviceId: deviceId,
      };
      console.log(`Created device with device ID ${deviceId}`);
      res.send(dev);
    } else {
      throw new Error("create response was falsy");
    }
  } catch (ex) {
    console.error("Unable to create device", ex);
    res.status(400).send(
        {
          error: `Unable to create device, ${ex}`,
        });
  }
});

export {
  getRegistryPath,
  getClient,
  getDeviceId,
  getKeys,
  getDeviceCreateReq,
  createDevice,
};
