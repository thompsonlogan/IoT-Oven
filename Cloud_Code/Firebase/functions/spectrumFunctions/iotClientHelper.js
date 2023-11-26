import { google } from "googleapis";
import "dotenv/config";

const getRegistryPath = () => {
  const projectId = process.env.PROJECT_ID;
  const projectLocation = process.env.PROJECT_LOCATION;
  const registryName = process.env.TOASTER_OVEN_REGISTRY;

  const projectPath = `projects/${projectId}`;
  const locationPath = `locations/${projectLocation}`;
  const registryPath = `registries/${registryName}`;

  return `${projectPath}/${locationPath}/${registryPath}`;
};

const getClient = async () => {
  // get auth from google for IoT Core
  const newAuth = await google.auth.getClient({
    scopes: ["https://www.googleapis.com/auth/cloud-platform"],
  });

  // create a new cloud IoT client
  const client = google.cloudiot({
    version: "v1",
    auth: newAuth,
  });

  return client;
};

export {
  getRegistryPath,
  getClient,
};
