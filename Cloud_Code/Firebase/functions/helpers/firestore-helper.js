import { Firestore } from "@google-cloud/firestore";


export default class FirestoreHelperFactory {
  /**
   * default creator for the FirestoreHelper class using firestore
   * @returns FirestoreHelper using firestore
   */
  static createHelper() {
    const database = new Firestore();
    database.settings({ ignoreUndefinedProperties: true });
    return new FirestoreHelper(database);
  }
}

export class FirestoreHelper {
  /**
   * Helper class for getting objects from the database
   * @param {*} database to get documents from
   */
  constructor(database) {
    this.database = database;
  }

  /**
   * Retrieve the document at the given endpoint
   * @param {*} endpoint to get from
   * @returns document data
   */
  async getEndpointData(endpoint) {
    const retDoc = await this.database.doc(endpoint).get();

    if (!retDoc.exists) {
      throw new Error("deviceNotFound");
    }
    return retDoc.data();
  }

  /**
   * Get all the devices with properties for the given user
   * @param {string} userId the user to get documents for
   * @returns the collection document
   */
  async getUserDeviceDocuments(userId) {
    const collection = await this.database.collection("deviceProperties").where("owner", "==", userId).get();
    return collection.docs;
  }

  /**
   * Deletes the given user id from the users collection
   * @param {string} userId to delete in the database
   */
  async deleteUser(userId) {
    const userRef = this.database.doc(`users/${userId}`);
    await userRef.delete();
  }

  /**
   * Updates the device config collection using the device model desired state
   * @param {*} device the model to pull the desired state from
   */
  async updateDevice(device) {
    if (device.state != null) {
      await this.database.doc(`deviceConfiguration/${device.id}`).update({ "config": device.state });
    }
  }
}
