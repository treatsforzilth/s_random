/*
reimplementation of dooms rng code fuck you if you ever watched decino you
should know how it works
*/

#include <stdint.h>
#include "s_random.h"

/*
heres a big ass table of random numbers that i generated cuz reusing the
one from doom would probably violate gpl
*/
uint8_t Table[256] = {
  237, 210, 76, 134, 100, 135, 223, 102, 157, 234, 245, 88, 135, 20, 7, 63,
  72, 71, 51, 231, 5, 60, 92, 107, 18, 191, 110, 56, 151, 242, 194, 133,
  196, 15, 11, 40, 150, 235, 142, 51, 213, 131, 140, 92, 151, 147, 155, 223,
  218, 206, 198, 223, 10, 35, 75, 29, 226, 185, 85, 122, 171, 23, 255, 111,
  38, 10, 151, 188, 245, 37, 240, 202, 168, 124, 38, 63, 15, 194, 31, 233,
  144, 229, 201, 155, 8, 20, 184, 235, 205, 13, 101, 121, 36, 100, 232, 75,
  110, 128, 7, 100, 165, 247, 46, 78, 115, 85, 141, 130, 23, 172, 108, 167,
  146, 53, 66, 154, 73, 250, 133, 22, 7, 234, 143, 44, 78, 120, 119, 189,
  248, 126, 33, 157, 118, 79, 235, 233, 164, 121, 108, 187, 37, 216, 99, 183,
  13, 165, 82, 86, 160, 215, 108, 167, 194, 252, 211, 16, 116, 74, 205, 108,
  201, 238, 9, 63, 62, 245, 40, 226, 110, 148, 158, 147, 108, 1, 75, 121,
  166, 157, 207, 70, 116, 60, 238, 54, 56, 193, 71, 172, 12, 20, 24, 213,
  3, 33, 20, 65, 22, 60, 35, 132, 209, 193, 24, 61, 194, 99, 183, 105,
  0, 134, 175, 116, 194, 157, 171, 250, 95, 242, 166, 107, 6, 190, 64, 9,
  224, 84, 74, 246, 144, 110, 123, 97, 47, 147, 159, 242, 246, 86, 91, 246,
  220, 10, 106, 159, 168, 21, 153, 7, 7, 64, 114, 14, 254, 178, 23, 222
};

// separate global (w) and local (v) indices for something like netplay
uint8_t W_Index;
uint8_t V_Index;

/*
these 2 functions return their respective value from the table then add one

these start at the same value but its expected that theyll desync at some
point during gameplay
*/
uint8_t W_Random(void){
  W_Index += 1;
  return Table[W_Index];
};

uint8_t V_Random(void){
  V_Index += 1;
  return Table[V_Index];
};

// reset the rng indices, this is used when loading a level
void RNG_Clean(void){
  W_Index = V_Index = 0;
}
