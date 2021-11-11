#include "FgcMode.h"

FgcMode::FgcMode(socd::SocdType socdType, state::InputState &rInputState,
                 CommunicationBackend *communicationBackend)
    : ControllerMode(socdType, rInputState, communicationBackend) {
  mSocdPairs.push_back(socd::SocdPair{&rInputState.left, &rInputState.right});
}

void FgcMode::HandleSocd() {
  if (mrInputState.down && (mrInputState.mod_x || mrInputState.c_up)) {
    mrInputState.down = false;
  }
  InputMode::HandleSocd();
}

void FgcMode::UpdateDigitalOutputs() {
  // Directions
  mOutputState.dpadLeft = mrInputState.left;
  mOutputState.dpadRight = mrInputState.right;
  mOutputState.dpadDown = mrInputState.down;
  mOutputState.dpadUp = mrInputState.mod_x || mrInputState.a;

  // Menu keys
  mOutputState.start = mrInputState.start;
  mOutputState.select = mrInputState.select;
  mOutputState.home = mrInputState.home;

  // Right hand top row (home row)
  mOutputState.a = mrInputState.b;
  mOutputState.b = mrInputState.x;
  mOutputState.triggerRDigital = mrInputState.z;
  mOutputState.triggerLDigital = mrInputState.up;

  // Right hand bottom row
  mOutputState.x = mrInputState.r;
  mOutputState.y = mrInputState.y;
  mOutputState.buttonR = mrInputState.lightshield;
  mOutputState.buttonL = mrInputState.midshield;
}

void FgcMode::UpdateAnalogOutputs() {
  mOutputState.leftStickX = 128;
  mOutputState.leftStickY = 128;
  mOutputState.rightStickX = 128;
  mOutputState.rightStickY = 128;
}
