#ifndef PINOUT_HTANGL_PROTO_H_HADOE
#define PINOUT_HTANGL_PROTO_H_HADOE

// Changing pin assignments will change button assignments for all game modes.
// Do not change the GCC_Data pin
namespace pinout {
enum pinout {
  GCC_DATA = A0,

  L = A5,
  LEFT = A4,
  DOWN = A3,
  RIGHT = 15,
  MODX = 16,
  MODY = 14,

  SELECT = 0,
  START = 1,
  HOME = 2,

  CLEFT = 8,
  CUP = 11,
  CDOWN = 7,
  A = 9,
  CRIGHT = 10,

  B = A1,
  X = A2,
  Z = 3,
  UP = 4,

  R = 6,
  Y = 5,
  LIGHTSHIELD = 13,
  MIDSHIELD = 12,
};
} // namespace pinout

#endif /* end of include guard: PINOUT_HTANGL_PROTO_H_HADOE */
