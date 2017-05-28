#ifndef UTIL_H
#define UTIL_H

unsigned char portByteIn(unsigned short port);
void portByteOut(unsigned short port, unsigned char value);
unsigned short portWordIn(unsigned short port);

#endif
