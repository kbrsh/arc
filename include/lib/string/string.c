#include "../string.h"

u32 strlen(s8 *str) {
  // Iterate through null terminated string and find length
  u32 i = 0;
  while(str[i] != 0) {
    i++;
  }
  return i;
}

void memset(void *voidPointer, u32 item, u64 length) {
  // Fill memory
  unsigned char *pointer = (unsigned char*) voidPointer;
  while(length--) {
    *pointer++ = item;
  }
}
