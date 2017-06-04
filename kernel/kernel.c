#include "kernel.h"
#include <ample/print.h>
#include <lib/stdio.h>

void _start(void) {
  clear();
  printkCenter("Ample");
  clear();
  printk("\n");
  printk("Ample");
  printk("\n\n");
  writek(">\t");
}
