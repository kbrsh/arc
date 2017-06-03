#ifndef PRINT_H
#define PRINT_H

#include "../../util/util.h"
#include <ample/stdio.h>

void clear(void);

#define writek(str, ...) { u32 size = calcf(str, ##__VA_ARGS__); s8 buf[size]; sprintf(buf, str, ##__VA_ARGS__); _writek(buf); }
void _writek(s8 *str);

#define printk(str, ...) { u32 size = calcf(str, ##__VA_ARGS__); s8 buf[size]; sprintf(buf, str, ##__VA_ARGS__); _printk(buf); }
void _printk(s8 *str);

void printkCenter(s8 *str);

#endif
