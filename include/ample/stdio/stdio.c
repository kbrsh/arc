#include "../stdio.h"
#include <ample/stdarg.h>

void _sprintf(s8 *buf, const s8 *str, ...) {
  va_list list;
  va_start(list, str);

  u32 i = 0;
  s8 ch;
  while(str[i] != 0) {
    ch = str[i];
    if(ch == '%') {
      
    } else {
      buf[i] = str[i];
    }

    i++;
  }

  buf[i] = '\0';
}
