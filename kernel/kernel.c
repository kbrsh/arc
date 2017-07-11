#include "kernel.h"
#include <arc/print.h>

#include "./cpu/idt.h"

void _start(void) {
  clear();
  initIDT();
  __asm__ __volatile__("int $2");
  printk("done");
}
