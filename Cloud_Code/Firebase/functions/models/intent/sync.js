export default class Sync {
  constructor(id, userID, deviceMetadataList) {
    this.requestId = id;
    this.payload = {
      "agentUserId": userID,
      "devices": deviceMetadataList,
    };
  }
}
