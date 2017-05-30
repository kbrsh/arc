#include "../print.h"
#include "../../../drivers/monitor/monitor.h"

void clear(void) {
  monitorClear();
}

void writek(s8 *fmt) {
  monitorWrite(fmt);
}

void printk(s8 *fmt) {
  monitorWrite(fmt);
  monitorWriteChar('\n');
}

void printkCenter(s8 *fmt) {
  monitorPrintCenter(fmt);
}
