#ifndef _MODES_DOOMKEYBOARDMODE_HPP
#define _MODES_DOOMKEYBOARDMODE_HPP

#include "core/KeyboardMode.hpp"
#include "core/socd.hpp"
#include "core/state.hpp"

class DoomKeyboardMode : public KeyboardMode {
  public:
    DoomKeyboardMode(socd::SocdType socd_type);

  private:
    void UpdateKeys(InputState &inputs);
};

#endif
