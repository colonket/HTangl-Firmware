#ifndef PINOUT_HTANGL_V1_H_HADOE
#define PINOUT_HTANGL_V1_H_HADOE

// Changing pin assignments will change button assignments for all game modes.
// Do not change the GCC_Data pin
namespace pinout {
enum pinout {
  GCC_DATA = 8,

  L = 6,
  LEFT = 4,
  DOWN = 0,
  RIGHT = 1,
  MODX = 14,
  MODY = 16,

  SELECT = 2,
  START = 3,
  HOME = 5,

  CLEFT = A2,
  CUP = A3,
  CDOWN = 15,
  A = A5,
  CRIGHT = A4,

  B = 7,
  X = 9,
  Z = 12,
  UP = A0,

  R = 10,
  Y = 11,
  LIGHTSHIELD = 13,
  MIDSHIELD = A1,
};
} // namespace pinout

#endif /* end of include guard: PINOUT_HTANGL_V1_H_HADOE */
