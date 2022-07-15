#include "modes/FgcMode.hpp"

FgcMode::FgcMode(socd::SocdType socd_type) : ControllerMode(socd_type) {
    _socd_pair_count = 1;
    _socd_pairs = new socd::SocdPair[_socd_pair_count]{
        socd::SocdPair{&InputState::left, &InputState::right},
    };
}

void FgcMode::HandleSocd(InputState &inputs) {
    if (inputs.down && (inputs.mod_x || inputs.a)) {
        inputs.down = false;
    }
    InputMode::HandleSocd(inputs);
}

void FgcMode::UpdateDigitalOutputs(InputState &inputs, OutputState &outputs) {
    // Directions
    outputs.dpadLeft = inputs.left;
    outputs.dpadRight = inputs.right;
    outputs.dpadDown = inputs.down;
    outputs.dpadUp = inputs.mod_x || inputs.a;

    // Menu keys
    outputs.start = inputs.start;
    outputs.select = inputs.select;
    outputs.home = inputs.home;

    // Right hand top row (home row)
    outputs.x = inputs.b;
    outputs.y = inputs.x;
    outputs.buttonR = inputs.z;
    outputs.buttonL = inputs.up;

    // Right hand bottom row
    outputs.a = inputs.r;
    outputs.b = inputs.y;
    outputs.triggerRDigital = inputs.lightshield;
    outputs.triggerLDigital = inputs.midshield;
}

void FgcMode::UpdateAnalogOutputs(InputState &inputs, OutputState &outputs) {
    outputs.leftStickX = 128;
    outputs.leftStickY = 128;
    outputs.rightStickX = 128;
    outputs.rightStickY = 128;
}
