#ifndef SETUP_HTANGL_V1_H_HADOE2
#define SETUP_HTANGL_V1_H_HADOE2

#include "pinout_htangl_v1.h"

#include "core/CommunicationBackend.h"
#include "core/InputMode.h"
#include "core/socd.h"
#include "core/state.h"
#include "comms/DInputBackend.h"
#include "comms/GamecubeBackend.h"
#include "modes/Melee20Button.h"
#include "modes/ProjectM.h"
#include "modes/Ultimate.h"
#include "modes/Nasb.h"

CommunicationBackend *gCurrentBackend;
InputMode *gCurrentMode;
state::InputState gInputState;

void initialise() {
  // Hold C-Down on plugin for Gamecube/Wii backend
  if (gInputState.c_down) {gCurrentBackend = new GamecubeBackend(125, pinout::GCC_DATA);} 
  // Hold A for GC adapater backend
  else if (gInputState.a) {gCurrentBackend = new GamecubeBackend(0, pinout::GCC_DATA);} 
  
  else {
    gCurrentBackend = new DInputBackend();
    // Input viewer only used when connected to PC i.e. when using DInput mode.
    Serial.begin(115200, SERIAL_8N1);
  }

  /* Always start in Melee mode. Must set mode only after initialising the
     backend. */
  gCurrentMode =
      new Melee20Button(socd::SOCD_2IP_NO_REAC, gInputState, gCurrentBackend);
}

#endif /* end of include guard: SETUP_HTANGL_V1_H_HADOE2 */
