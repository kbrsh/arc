#include "../stdlib.h"

u32 intlen(u32 num) {
  u32 length = 1;

  while(num > 9) {
    length++;
    num /= 10;
  }

  return length;
}

void* malloc(u32 size) {
  return (void*)(0x00000f);
}
