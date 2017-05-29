#include "monitor.h"
#include "../../util/util.h"

unsigned short *videoMemory = (unsigned short*) VIDEO_LOCATION;
unsigned char cursorX = 0;
unsigned char cursorY = 0;

void scrollToBottom() {

}

void updateCursorPosition() {
  unsigned short cursorPosition = cursorY * MAX_COLS + cursorX;
  portByteOut(SCREEN_CONTROL_PORT, 14);
  portByteOut(SCREEN_DATA_PORT, cursorPosition >> 8);
  portByteOut(SCREEN_CONTROL_PORT, 15);
  portByteOut(SCREEN_DATA_PORT, cursorPosition);
}

void monitorPrintChar(char ch) {
  unsigned short *videoMemory = (unsigned short*) VIDEO_LOCATION;
  unsigned short *videoMemoryLocation;

  if(ch == '\n') {
    cursorX = 0;
    cursorY++;
  } else {
    videoMemoryLocation = videoMemory + (cursorY * MAX_COLS + cursorX);
    *videoMemoryLocation = (ch) | ((0 << 4) | (15 & 0x0F) << 8);
    cursorX++;
  }

  if(cursorX >= MAX_COLS) {
    cursorX = 0;
    cursorY++;
  }

  updateCursorPosition();
}

void monitorClear() {
  unsigned int i;
  unsigned short *videoMemory = (unsigned short*) VIDEO_LOCATION;

  for(i = 0; i < SIZE; i++) {
    videoMemory[i] = SPACE;
  }

  cursorX = 0;
  cursorY = 0;
  updateCursorPosition();
}

void monitorWrite(char *str) {
  unsigned int i = 0;
  while(str[i] != 0) {
    monitorPrintChar(str[i++]);
  }
}

void monitorPrint(char *str) {
  monitorWrite(str);
  monitorPrintChar('\n');
}

void monitorPrintCenter(char *str) {
  unsigned int len = length(str);
  cursorX = (MAX_COLS / 2) - len;
  cursorY = (MAX_ROWS / 2) - 1;
  monitorWrite(str);
}
