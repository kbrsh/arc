#include "../print.h"
#include "../../../drivers/monitor/monitor.h"

void clear(void) {
  // Clear Monitor
  monitorClear();
}

void _writek(s8 *str) {
  // Write to Monitor
  monitorWrite(str);
}

void _printk(s8 *str) {
  // Print to Monitor
  monitorWrite(str);
  monitorWriteChar('\n');
}

void printkCenter(s8 *str) {
  // Print in Center of Monitor
  monitorPrintCenter(str);
}
