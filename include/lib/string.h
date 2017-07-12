#ifndef STRING_H
#define STRING_H

#include <util/types.h>

u32 strlen(s8 *str);

s8 strcpy(s8 *str, const s8 *copy);

s8 strcat(s8 *str, const s8 *add);

void memset(void *pointer, u32 item, u64 length);

#endif
