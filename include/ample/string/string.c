#include "../string.h"

u32 strlen(s8 *str) {
  u32 i = 0;
  while(str[i++] != 0) {}
  return i - 1;
}
