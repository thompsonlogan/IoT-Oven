export default class Execute {
  constructor(id, commands) {
    this.requestId = id;
    this.payload = {
      "commands": commands,
    };
  }
}

class Command {
  constructor(status) {
    this.ids = [];
    this.status = status;
  }
}

export class Success extends Command {
  constructor(states) {
    super("SUCCESS");
    this.states = states;
  }
}

export class Pending extends Command {
  constructor(states) {
    super("PENDING");
    this.states = states;
  }
}

export class Offline extends Command {
  constructor() {
    super("OFFLINE");
  }
}

export class Error extends Command {
  constructor(error) {
    super("ERROR");
    this.errorCode = error;
  }
}
