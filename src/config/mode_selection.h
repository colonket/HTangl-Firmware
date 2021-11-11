#ifndef MODE_SELECTION_H_METMBOLA
#define MODE_SELECTION_H_METMBOLA

#include "core/InputMode.h"
#include "core/state.h"
#include "modes/Melee20Button.h"
#include "modes/ProjectM.h"
#include "modes/Ultimate.h"
#include "modes/FgcMode.h"
#include "modes/DefaultKeyboardMode.h"
#include "modes/RoA.h"
#include "modes/Nasb.h"

extern CommunicationBackend *gCurrentBackend;
extern InputMode *gCurrentMode;
extern state::InputState gInputState;

void selectInputMode() 
{
  if (gInputState.mod_x && !gInputState.mod_y && gInputState.start) 
{
      // Melee Mode
      if (gInputState.l) {delete gCurrentMode; gCurrentMode = new Melee20Button(socd::SOCD_2IP_NO_REAC, gInputState, gCurrentBackend);} 
      // ProjectM Mode
      else if (gInputState.left) {delete gCurrentMode; gCurrentMode = new ProjectM(socd::SOCD_2IP_NO_REAC, gInputState, gCurrentBackend, true, false);} 
      // Ultimate Mode
      else if (gInputState.down) {delete gCurrentMode; gCurrentMode = new Ultimate(socd::SOCD_2IP_NO_REAC, gInputState, gCurrentBackend);} 
      // FGC Mode
      else if (gInputState.right) {delete gCurrentMode; gCurrentMode = new FgcMode(socd::SOCD_NEUTRAL, gInputState, gCurrentBackend);}
} 
  else if (gInputState.mod_y && !gInputState.mod_x && gInputState.start) 
{
      // Keyboard Mode
      if (gInputState.l) {delete gCurrentMode; gCurrentMode = new DefaultKeyboardMode(socd::SOCD_2IP, gInputState);}
      // Rivals of Aether Mode
      else if (gInputState.left) {delete gCurrentMode; gCurrentMode = new RoA(socd::SOCD_2IP_NO_REAC, gInputState, gCurrentBackend);}
      // Nickelodeon All Star Brawl Mode
      else if (gInputState.down) {delete gCurrentMode; gCurrentMode = new Nasb(socd::SOCD_2IP, gInputState, gCurrentBackend);} 
}
}

#endif /* end of include guard: MODE_SELECTION_H_METMBOLA */
