#ifndef STDARG_H
#define STDARG_H

#include <util/types.h>

typedef struct {
  void *cur;
} va_list;

#define va_start(list, ref) list.cur = &ref + sizeof(ref);

#define va_arg(list, type) *(type*)list.cur; list.cur += sizeof(type);

#endif
