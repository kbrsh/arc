#include "../print.h"
#include "../../../drivers/monitor/monitor.h"

void clear(void) {
  monitorClear();
}

void printk(s8 *fmt) {
  monitorPrint(fmt);
}

void printkCenter(s8 *fmt) {
  monitorPrintCenter(fmt);
}
