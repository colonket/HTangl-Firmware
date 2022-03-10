#ifndef PINOUT_HTANGL_V2_H_HADOE
#define PINOUT_HTANGL_V2_H_HADOE

// Changing pin assignments will change button assignments for all game modes.
// Do not change the GCC_Data pin
namespace pinout {
enum pinout {
  GCC_DATA = 13,

  L = 12,
  LEFT = 7,
  DOWN = 11,
  RIGHT = 5,
  MODX = 9,
  MODY = A1,

  SELECT = 2,
  START = 1,
  HOME = 3,

  CLEFT = A3,
  CUP = A4,
  CDOWN = A0,
  A = 10,
  CRIGHT = A2,

  B = 0,
  X = 4,
  Z = 6,
  UP = 8,

  R = 16,
  Y = 15,
  LIGHTSHIELD = A5,
  MIDSHIELD = 14,
};
} // namespace pinout

#endif /* end of include guard: PINOUT_HTANGL_V2_H_HADOE */
