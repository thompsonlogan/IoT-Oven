import { initializeApp } from "firebase-admin/app";
import { getAuth } from "firebase-admin/auth";
import { getFirestore } from "firebase-admin/firestore";

const app = initializeApp();
const firestore = getFirestore(app);
const auth = getAuth(app);

const _auth = auth;
export { _auth as auth };
const _firestore = firestore;
export { _firestore as firestore };
