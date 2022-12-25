#include "modes/DoomKeyboardMode.hpp"

#include "core/socd.hpp"
#include "core/state.hpp"

/**
 * 
 * Play Shareware DOOM online with friends or by yourself at: 
 * https://silentspacemarine.com 
 * 
 * The Original DOOM README:
 * https://classicdoom.com/doominfo.htm 
 * 
 */

DoomKeyboardMode::DoomKeyboardMode(socd::SocdType socd_type) : KeyboardMode(socd_type) {}

void DoomKeyboardMode::UpdateKeys(InputState &inputs) {
    Press(HID_KEY_1, inputs.l);					// 1	Fist
    Press(HID_KEY_A, inputs.left);				// A	Strafe Left 
    Press(HID_KEY_W, inputs.down);				// W	Move Forward
    Press(HID_KEY_D, inputs.right);				// D	Strafe Right
    Press(HID_KEY_SHIFT_LEFT, inputs.mod_x);    // LShift	Sprint
    Press(HID_KEY_SHIFT_RIGHT, inputs.mod_y);   // RShift	Sprint
    Press(HID_KEY_ARROW_DOWN, inputs.select);	// Down		Menu Down
    Press(HID_KEY_ENTER, inputs.start); 		// Enter	Menu Select
    Press(HID_KEY_ARROW_UP, inputs.home);		// Up	Menu Up
    Press(HID_KEY_6, inputs.r);					// 6	Plasma Rifle
    Press(HID_KEY_7, inputs.y);					// 7	BFG
    //Press(NULL, inputs.lightshield);			// UNUSED
    //Press(NULL, inputs.midshield);			// UNUSED
    Press(HID_KEY_O, inputs.b);         		// O	Turn Left
    Press(HID_KEY_P, inputs.x);         		// P	Turn Right
    Press(HID_KEY_E, inputs.z);					// E	Use
    Press(HID_KEY_S,inputs.up);        			// S	Move Backwards
    Press(HID_KEY_2, inputs.c_down);            // 2	Pistol
    Press(HID_KEY_3, inputs.c_left);            // 3	Shotgun
    Press(HID_KEY_4, inputs.c_up);				// 4	Chaingun
    Press(HID_KEY_5, inputs.c_right);           // 5	Rocket Launcher
    Press(HID_KEY_SPACE, inputs.a);             // Space	Shoot
}
