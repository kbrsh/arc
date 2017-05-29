#ifndef UTIL_H
#define UTIL_H

typedef unsigned int u32;
typedef int s32;
typedef unsigned short u16;
typedef short s16;
typedef unsigned char u8;
typedef char s8;

u8 portByteIn(u16 port);
void portByteOut(u16 port, u8 value);
u16 portWordIn(u16 port);

#endif
