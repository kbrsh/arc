#include "kernel.h"
#include "../drivers/monitor/monitor.h"
#include <arc/print.h>

void _start(void) {
  clear();
  monitorWriteChar('a');
  // printkCenter("Arc");
  // clear();
  // printk("\n");
  // printk("Arc");
  // printk("\n\n");
  // writek(">\t");
}
