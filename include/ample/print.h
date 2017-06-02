#ifndef PRINT_H
#define PRINT_H

#include "../../util/util.h"
#include <ample/stdio.h>

void clear(void);

#define writek(str, ...) { s8 buf[sizeof(str)]; sprintf(buf, str, ##__VA_ARGS__); _writek(buf); }
void _writek(s8 *str);

#define printk(str, ...) { s8 buf[sizeof(str)]; sprintf(buf, str, ##__VA_ARGS__); _printk(buf); }
void _printk(s8 *str);

void printkCenter(s8 *str);

#endif
