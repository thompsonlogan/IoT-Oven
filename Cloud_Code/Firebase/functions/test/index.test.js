import "dotenv/config";
// configure your testing environment to point to the testing firebase instance
import firestoreTestFn from "@dig-platform/firestore-test";
const firestoreTest = firestoreTestFn({
  // databaseURL: 'https://oven-controls-on-home-app-default-rtdb.firebaseio.com',
  storageBucket: "spectrum-brands-main-project.appspot.com",
  projectId: process.env.PROJECT_ID,
}, "smart-home-key.json");

// get the core firebase testing utilities
const test = firestoreTest.firebaseTest();
