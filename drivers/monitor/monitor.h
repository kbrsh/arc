#ifndef MONITOR_H
#define MONITOR_H

#include "../../util/util.h"

#define VIDEO_LOCATION 0xb8000
#define MAX_ROWS 25
#define MAX_COLS 80
#define SIZE 25 * 80

#define SPACE 3872

#define SCREEN_CONTROL_PORT 0x3d4
#define SCREEN_DATA_PORT 0x3d5

void monitorClear(void);
void monitorWrite(s8 *ch);
void monitorPrint(s8 *ch);
void monitorPrintCenter(s8 *ch);

#endif
