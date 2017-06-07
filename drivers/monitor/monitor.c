#include "monitor.h"
#include "../port/port.h"
#include <lib/string.h>

u16 cursorX = 0;
u16 cursorY = 0;

void scrollToBottom(void) {

}

void updateCursorPosition(void) {
  u16 cursorPosition = cursorY * MAX_COLS + cursorX;
  portByteOut(0x3D4, 14);
  portByteOut(0x3D5, cursorPosition >> 8);
  portByteOut(0x3D4, 15);
  portByteOut(0x3D5, cursorPosition);
}

void monitorWriteChar(s8 ch) {
  u16 *videoMemory = (u16*)VIDEO_LOCATION;

  switch(ch) {
    case '\n':
      cursorX = 0;
      cursorY++;
      break;
    case '\t':
      cursorX += 2;
      break;
    case '\r':
      cursorX = 0;
      break;
    default:
      videoMemory[cursorY * MAX_COLS + cursorX] = ch | 3840;
      cursorX++;
  }

  if(cursorX >= MAX_COLS) {
    cursorX = 0;
    cursorY++;
  }

  updateCursorPosition();
}

void monitorClear(void) {
  u16 *videoMemory = (u16*)VIDEO_LOCATION;
  u16 i;

  for(i = 0; i < SIZE; ++i) {
    videoMemory[i] = 0x20 | 3840;
  }

  cursorX = 0;
  cursorY = 0;
  updateCursorPosition();
}

void monitorWrite(s8 *str) {
  u16 i = 0;
  while(str[i] != 0) {
    monitorWriteChar(str[i++]);
  }
}

void monitorPrintCenter(s8 *str) {
  u32 len = strlen(str);
  cursorX = (MAX_COLS / 2) - len;
  cursorY = (MAX_ROWS / 2) - 1;
  monitorWrite(str);
}
