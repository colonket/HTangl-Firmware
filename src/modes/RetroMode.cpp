#include "modes/RetroMode.hpp"

RetroMode::RetroMode(socd::SocdType socd_type) : ControllerMode(socd_type) {
    _socd_pair_count = 2;
    _socd_pairs = new socd::SocdPair[_socd_pair_count]{
        socd::SocdPair{&InputState::left, &InputState::right},
        socd::SocdPair{&InputState::down, &InputState::mod_x},
    };
}

void RetroMode::UpdateDigitalOutputs(InputState &inputs, OutputState &outputs) {
    // Directions
    outputs.dpadLeft = inputs.left;
    outputs.dpadRight = inputs.right;
    outputs.dpadDown = inputs.down;
    outputs.dpadUp = inputs.mod_x;

    // Menu keys
    outputs.start = inputs.start;
    outputs.select = inputs.select;
    outputs.home = inputs.home;

    // Face buttons and triggers
    outputs.a = inputs.a;
    outputs.b = inputs.b;
    outputs.y = inputs.x;
    outputs.x = inputs.z;
    outputs.buttonR = inputs.up;
    outputs.buttonL = inputs.l;
    outputs.triggerRDigital = inputs.r;
    outputs.triggerLDigital = inputs.y;
}

void RetroMode::UpdateAnalogOutputs(InputState &inputs, OutputState &outputs) {
    outputs.leftStickX = 128;
    outputs.leftStickY = 128;
    outputs.rightStickX = 128;
    outputs.rightStickY = 128;
}
