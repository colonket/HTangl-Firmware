#include "modes/DefaultKeyboardMode.hpp"

#include "core/socd.hpp"
#include "core/state.hpp"

DefaultKeyboardMode::DefaultKeyboardMode(socd::SocdType socd_type) : KeyboardMode(socd_type) {}

void DefaultKeyboardMode::UpdateKeys(InputState &inputs) {
    Press(HID_KEY_Q, inputs.l);
    Press(HID_KEY_A, inputs.left);
    Press(HID_KEY_S, inputs.down);
    Press(HID_KEY_D, inputs.right);
    Press(HID_KEY_W, inputs.mod_x);
    Press(HID_KEY_E, inputs.mod_y);
    Press(HID_KEY_Z, inputs.select);
    Press(HID_KEY_X, inputs.start);
    Press(HID_KEY_C, inputs.home);
    Press(HID_KEY_H, inputs.r);
    Press(HID_KEY_J, inputs.y);
    Press(HID_KEY_K, inputs.lightshield);
    Press(HID_KEY_L, inputs.midshield);
    Press(HID_KEY_U, inputs.b);
    Press(HID_KEY_I, inputs.x);
    Press(HID_KEY_O, inputs.z);
    Press(HID_KEY_P, inputs.up);
    Press(HID_KEY_8, inputs.c_up);
    Press(HID_KEY_4, inputs.c_left);
    Press(HID_KEY_6, inputs.c_right);
    Press(HID_KEY_5, inputs.a);
    Press(HID_KEY_2, inputs.c_down);
}
