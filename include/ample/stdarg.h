#ifndef STDARG_H
#define STDARG_H

#include "../../util/util.h"

typedef struct {
  void *cur;
  u32 offset;
} va_list;

#define va_start(list, ref) list.cur = &ref; list.offset = 1;

#define va_arg(list, type) *(type*)(&(*(typeof(list.cur)*)list.cur) + list.offset++);

#endif
