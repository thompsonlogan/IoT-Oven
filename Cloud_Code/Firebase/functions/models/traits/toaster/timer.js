const attribute = {
  "maxTimerLimitSec": 157784760,
  "commandOnlyTimer": false,
};

const name = "action.devices.traits.Timer";
const commands = [
  "action.devices.commands.TimerPause",
  "action.devices.commands.TimerResume",
  "action.devices.commands.TimerCancel",
  "action.devices.commands.TimerStart",
  "action.devices.commands.TimerAdjust",
];

export class Timer {
  constructor(state) {
    if (state != null) {
      this.timerRemainingSec = state.timerRemainingSec;
      this.timerPaused = state.timerPaused;
    }
  }

  get attribute() {
    return attribute;
  }

  get name() {
    return name;
  }

  get commands() {
    return commands;
  }

  get reportState() {
    return {
      "timerRemainingSec": this.timerRemainingSec,
      "timerPaused": this.timerPaused,
    };
  }

  start(params) {
    this.timerRemainingSec = params.timerTimeSec;
  }

  cancel(params) {
    this.timerRemainingSec = -1;
  }

  adjust(params) {
    this.timerRemainingSec += params.timerTimeSec;
  }

  pause(params) {
    this.timerPaused = true;
  }

  resume(params) {
    this.timerPaused = false;
  }

  execute(command, params) {
    if (command == "action.devices.commands.TimerPause") {
      this.pause(params);
    } else if (command == "action.devices.commands.TimerResume") {
      this.resume(params);
    } else if (command == "action.devices.commands.TimerCancel") {
      this.cancel(params);
    } else if (command == "action.devices.commands.TimerStart") {
      this.start(params);
    } else if (command == "action.devices.commands.TimerAdjust") {
      this.adjust(params);
    }
  }
}
