#include "../stdio.h"
#include <lib/string.h>
#include <lib/stdarg.h>
#include <lib/stdlib.h>
#include <ample/print.h>

u32 _calcf(const s8 *str, ...) {
  va_list list;
  va_start(list, str);

  u32 i = 0; // Current position in string
  u32 len = 1; // Total length (including NULL terminator)

  s8 ch; // Current character
  s8 special; // Current special identifier

  u32 intDigit;

  while(str[i] != 0) {
    ch = str[i];
    if(ch == '%') {
      special = str[i + 1]; // Get special identifier
      switch(special) {
        case 'c':
          // A character takes up a byte
          len++;
          break;

        case 'd':
          // A single digit takes up the length of the number
          intDigit = va_arg(list, u32);
          len += intlen(intDigit);
          break;
      }

      // Increment position in string
      i++;
    } else {
      // Increment length by a byte
      len++;
    }

    // Increment position in string
    i++;
  }

  return len;
}

void _sprintf(s8 *buf, const s8 *str, ...) {
  va_list list;
  va_start(list, str);

  u32 i = 0; // Position in string (str)
  u32 j = 0; // Position in buffer (buf)

  s8 ch; // Current character
  s8 special; // Current special identifier

  u32 intDigit;
  u32 length;

  while(str[i] != 0) {
    ch = str[i];
    if(ch == '%') {
      special = str[i + 1]; // Get special identifier
      switch(special) {
        case 'c':
          // Insert character
          buf[j] = va_arg(list, s8);
          break;

        case 'd':
          // Insert digit (as int)
          intDigit = va_arg(list, u32);
          length = intlen(intDigit);
          j += length;

          while(intDigit != 0) {
            j--;
            buf[j] = (char)(48 + (intDigit % 10));
            intDigit /= 10;
          }

          j += length - 1;
          break;
      }

      // Increment position in string to skip special identifier
      i++;
    } else {
      buf[j] = ch;
    }

    // Increment position in buffer
    j++;

    // Increment position in string
    i++;
  }

  buf[j] = '\0';
}
