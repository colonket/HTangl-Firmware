#include "modes/Platformer.hpp"

Platformer::Platformer(socd::SocdType socd_type) : ControllerMode(socd_type) {
    _socd_pair_count = 2;
    _socd_pairs = new socd::SocdPair[_socd_pair_count]{
        socd::SocdPair{&InputState::left, &InputState::right},
        socd::SocdPair{&InputState::down, &InputState::mod_x},
    };
}

void Platformer::UpdateDigitalOutputs(InputState &inputs, OutputState &outputs) {
    // Directions
    outputs.dpadLeft = inputs.left;
    outputs.dpadRight = inputs.right;
    outputs.dpadDown = inputs.down;
    outputs.dpadUp = inputs.mod_x;

    // Menu keys
    outputs.select = inputs.select;
    outputs.home = inputs.home;

    // For controllers with only 1 menu button Select/Home can be accessed with MX or MY + Start
    if (inputs.mod_x)
    {outputs.select = inputs.start;}
    else if (inputs.mod_y)
    {outputs.home = inputs.start;}
    else {outputs.start = inputs.start;}

    // Face buttons and triggers
    outputs.a = inputs.a;
    outputs.b = inputs.b;
    outputs.x = inputs.x;
    outputs.y = inputs.z;
    outputs.buttonR = inputs.up;
    outputs.buttonL = inputs.l;
    outputs.triggerRDigital = inputs.r;
    outputs.triggerLDigital = inputs.y;
}

void Platformer::UpdateAnalogOutputs(InputState &inputs, OutputState &outputs) {
    outputs.leftStickX = 128;
    outputs.leftStickY = 128;
    outputs.rightStickX = 128;
    outputs.rightStickY = 128;
}
