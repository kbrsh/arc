#include "../print.h"
#include "../../../drivers/monitor/monitor.h"

void clear(void) {
  monitorClear();
}

void writek(s8 *str) {
  monitorWrite(str);
}

void printk(s8 *str) {
  monitorWrite(str);
  monitorWriteChar('\n');
}

void printkCenter(s8 *str) {
  monitorPrintCenter(str);
}
