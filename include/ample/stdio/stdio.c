#include "../stdio.h"
#include <ample/stdarg.h>
#include <ample/stdlib.h>

void _sprintf(s8 *buf, const s8 *str, ...) {
  va_list list;
  va_start(list, str);

  u32 i = 0;
  s8 ch;
  s8 special;
  while(str[i] != 0) {
    ch = str[i];
    if(ch == '%') {
      special = str[i + 1];
      switch(special) {
        case 'c':
          buf[i] = va_arg(list, s8);
          break;
      }
      i++;
    } else {
      buf[i] = str[i];
    }

    i++;
  }

  buf[i] = '\0';
}
