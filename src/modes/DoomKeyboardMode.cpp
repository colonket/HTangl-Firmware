#include "modes/DoomKeyboardMode.hpp"

#include "core/socd.hpp"
#include "core/state.hpp"

DoomKeyboardMode::DoomKeyboardMode(socd::SocdType socd_type) : KeyboardMode(socd_type) {}

void DoomKeyboardMode::UpdateKeys(InputState &inputs) {
    Press(HID_KEY_E, inputs.l);         // E/Use
    Press(HID_KEY_A, inputs.left);      // A/Strafe Left 
    Press(HID_KEY_W, inputs.down);      // W/Move Forward
    Press(HID_KEY_D, inputs.right);     // D/Strafe Right
    //Press(HID_KEY_W, inputs.mod_x);
    //Press(HID_KEY_E, inputs.mod_y);
    //Press(HID_KEY_Z, inputs.select);
    Press(HID_KEY_ENTER, inputs.start); // Enter
    //Press(HID_KEY_C, inputs.home);
    //Press(HID_KEY_H, inputs.r);
    //Press(HID_KEY_J, inputs.y);
    //Press(HID_KEY_K, inputs.lightshield);
    //Press(HID_KEY_L, inputs.midshield);
    Press(HID_KEY_O, inputs.b);         // O/Turn Left
    Press(HID_KEY_P, inputs.x);         // P/Turn Right
    //Press(HID_KEY_O, inputs.z);
    Press(HID_KEY_ARROW_UP, inputs.c_up);       // Up
    Press(HID_KEY_ARROW_LEFT, inputs.c_left);   // Left
    Press(HID_KEY_ARROW_RIGHT, inputs.c_right); // Right
    Press(HID_KEY_SPACE, inputs.a);             // Space/Shoot
    Press(HID_KEY_2, inputs.c_down);            // Down
}
