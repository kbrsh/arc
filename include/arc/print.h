#ifndef PRINT_H
#define PRINT_H

#include <util/types.h>
#include <lib/stdio.h>
#include <lib/string.h>

void clear(void);

#define writek(str, ...) { u32 size = calcf(str, ##__VA_ARGS__); s8 buf[size]; sprintf(buf, str, ##__VA_ARGS__); _writek(buf); }
void _writek(s8 *str);

#define printk(str, ...) { u32 size = calcf(str, ##__VA_ARGS__); s8 buf[size]; sprintf(buf, str, ##__VA_ARGS__); _printk(buf); }
void _printk(s8 *str);

void printkCenter(s8 *str);

#define error(str, ...) { u32 size = 13 + calcf(str, ##__VA_ARGS__); u32 newStrSize = 13 + strlen(str); s8 newStr[newStrSize]; strcpy(newStr, "[Arc] ERROR: "); strcat(newStr, str); s8 buf[size]; sprintf(buf, newStr, ##__VA_ARGS__); _printk(buf); }

#endif
