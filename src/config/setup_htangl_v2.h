#ifndef SETUP_HTANGL_V2_H_HADOE
#define SETUP_HTANGL_V2_H_HADOE

#include "pinout_htangl_v2.h"

#include "core/CommunicationBackend.h"
#include "core/InputMode.h"
#include "core/socd.h"
#include "core/state.h"
#include "comms/DInputBackend.h"
#include "comms/GamecubeBackend.h"
#include "modes/Melee20Button.h"
#include "modes/ProjectM.h"
#include "modes/Ultimate.h"
#include "modes/RoA.h"
#include "modes/Nasb.h"

CommunicationBackend *gCurrentBackend;
InputMode *gCurrentMode;
state::InputState gInputState;

void initialise() {
  gCurrentBackend = new DInputBackend();

  delay(500);

  bool usb_connected = UDADDR & _BV(ADDEN);

  if (usb_connected) 
  {
    // Default to DInput mode
    // Input viewer only used when connected to PC i.e. when using DInput mode
    Serial.begin(115200, SERIAL_8N1);
  }
  else
  {
  delete gCurrentBackend;
  // Hold A for GC adapater backend, otherwise default to GC/Wii backend
  if (gInputState.a)
  {gCurrentBackend = new GamecubeBackend(0, pinout::GCC_DATA);}
  else
  {gCurrentBackend = new GamecubeBackend(125, pinout::GCC_DATA);}
  }

  /* Always start in Melee mode. Must set mode only after initialising the
     backend. */
  gCurrentMode =
      new Melee20Button(socd::SOCD_2IP_NO_REAC, gInputState, gCurrentBackend);
}

#endif /* end of include guard: SETUP_HTANGL_V2_H_HADOE */
