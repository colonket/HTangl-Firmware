#include "Nasb.h"

#define ANALOG_STICK_MIN 48
#define ANALOG_STICK_NEUTRAL 128
#define ANALOG_STICK_MAX 208

Nasb::Nasb(socd::SocdType socdType,
                             state::InputState &rInputState,
                             CommunicationBackend *communicationBackend)
    : ControllerMode(socdType, rInputState, communicationBackend) {
  mSocdPairs.push_back(socd::SocdPair{&rInputState.left, &rInputState.right});
  mSocdPairs.push_back(socd::SocdPair{&rInputState.down, &rInputState.up});
  mSocdPairs.push_back(
      socd::SocdPair{&rInputState.c_left, &rInputState.c_right});
  mSocdPairs.push_back(socd::SocdPair{&rInputState.c_down, &rInputState.c_up});

  mHorizontalSocd = false;
}

void Nasb::HandleSocd() {
  mHorizontalSocd = mrInputState.left && mrInputState.right;
  InputMode::HandleSocd();
}


void Nasb::UpdateDigitalOutputs() 
{
  mOutputState.a = mrInputState.a;
  mOutputState.b = mrInputState.b;
  mOutputState.y = mrInputState.x || mrInputState.y;
  mOutputState.x = mrInputState.z;
  mOutputState.triggerRDigital = mrInputState.r || mrInputState.l;
  mOutputState.buttonR = mrInputState.midshield;
  mOutputState.triggerLDigital = mrInputState.mod_x; 
  mOutputState.start = mrInputState.start;
  mOutputState.dpadUp = mrInputState.select || mrInputState.home;

  // D-Pad layer can be activated by holding Mod X + Mod Y
  if (mrInputState.mod_x && mrInputState.mod_y) 
  {
    mOutputState.dpadUp = mrInputState.c_up;
    mOutputState.dpadDown = mrInputState.c_down;
    mOutputState.dpadLeft = mrInputState.c_left;
    mOutputState.dpadRight = mrInputState.c_right;
  }
}

void Nasb::UpdateAnalogOutputs() 
{
  HandleVectors(
  // Left Stick Left
  mrInputState.left, 
  // Left Stick Right
  mrInputState.right, 
  // Left Stick Down
  mrInputState.down, 
  // Left Stick Up
  mrInputState.up, 
  // Right Stick Left
  mrInputState.c_left, 
  // Right Stick Right
  mrInputState.c_right,
  // Right Stick Down
  mrInputState.c_down, 
  // Right Stick Up
  mrInputState.c_up,

  ANALOG_STICK_MIN, ANALOG_STICK_NEUTRAL, ANALOG_STICK_MAX);
}
