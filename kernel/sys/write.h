#ifndef SYS_WRITE_H
#define SYS_WRITE_H

#include <util/types.h>

u8 write(u32 fd, const void* buf, u32 num);

#endif
