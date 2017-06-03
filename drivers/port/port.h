#ifndef PORT_H
#define PORT_H

#include <util/types.h>

u8 portByteIn(u16 port);
void portByteOut(u16 port, u8 value);
u16 portWordIn(u16 port);

#endif
