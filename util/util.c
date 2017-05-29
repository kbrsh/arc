#include "util.h"

unsigned int length(char *str) {
  unsigned int i = 0;
  unsigned int len = 0;
  while(str[i++] != 0) {
    len++;
  }
  return len;
}

unsigned char portByteIn(unsigned short port) {
  unsigned char output;
  __asm__("in %%dx, %%al" : "=a" (output) : "d" (port));
  return output;
}

void portByteOut(unsigned short port, unsigned char value) {
  __asm__("out %%al, %%dx" : : "a" (value), "d" (port));
}

unsigned short portWordIn(unsigned short port) {
  unsigned short output;
  __asm__("in %%dx, %%ax" : "=a" (output) : "d" (port));
  return output;
}
