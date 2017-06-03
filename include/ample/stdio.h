#ifndef STDIO_H
#define STDIO_H

#include "../../util/util.h"

#define calcf(str, ...) _calcf(str, ##__VA_ARGS__)
u32 _calcf(const s8 *str, ...);

#define sprintf(buf, str, ...) _sprintf(buf, str, ##__VA_ARGS__)
void _sprintf(s8 *buf, const s8 *str, ...);

#endif
