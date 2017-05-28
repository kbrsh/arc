#ifndef MONITOR_H
#define MONITOR_H

#define VIDEO_LOCATION 0xb8000
#define MAX_ROWS 25
#define MAX_COLS 80
#define SIZE 25 * 80

#define SPACE 0x20 | ((0 << 4) | (15 & 0x0F) << 8)

#define SCREEN_CONTROL_PORT 0x3d4
#define SCREEN_DATA_PORT 0x3d5

void monitorPrint(char *ch);

void monitorClear();

#endif
