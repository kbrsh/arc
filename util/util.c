#include "util.h"

u32 length(s8 *str) {
  u32 i = 0;
  u32 len = 0;
  while(str[i++] != 0) {
    len++;
  }
  return len;
}

u8 portByteIn(u16 port) {
  u8 output;
  __asm__("in %%dx, %%al" : "=a" (output) : "d" (port));
  return output;
}

void portByteOut(u16 port, u8 value) {
  __asm__("out %%al, %%dx" : : "a" (value), "d" (port));
}

unsigned short portWordIn(u16 port) {
  u16 output;
  __asm__("in %%dx, %%ax" : "=a" (output) : "d" (port));
  return output;
}
