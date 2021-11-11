#include "DefaultKeyboardMode.h"

DefaultKeyboardMode::DefaultKeyboardMode(socd::SocdType socdType,
                                         state::InputState &rInputState)
    : KeyboardMode(socdType, rInputState) {}

void DefaultKeyboardMode::SendKeys() {
  Press('q', mrInputState.l);
  Press('a', mrInputState.left);
  Press('s', mrInputState.down);
  Press('d', mrInputState.right);
  Press('w', mrInputState.mod_x);
  Press('e', mrInputState.mod_y);
  Press('z', mrInputState.select);
  Press('x', mrInputState.start);
  Press('c', mrInputState.home);
  Press('u', mrInputState.b);
  Press('i', mrInputState.x);
  Press('o', mrInputState.z);
  Press('p', mrInputState.up);
  Press('h', mrInputState.r);
  Press('j', mrInputState.y);
  Press('k', mrInputState.lightshield);
  Press('l', mrInputState.midshield);
  Press('5', mrInputState.a);
  Press('8', mrInputState.c_up);
  Press('4', mrInputState.c_left);
  Press('6', mrInputState.c_right);
  Press('2', mrInputState.c_down);
}
