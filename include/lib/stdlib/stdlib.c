#include "../stdlib.h"

u32 intlen(u32 num) {
  // Length starts at one
  u32 length = 1;

  // Keep dividing by ten (base) to reach length
  while(num > 9) {
    length++;
    num /= 10;
  }

  return length;
}

void* malloc(u32 size) {
  // Placeholder
  return (void*)(0x00000f);
}
