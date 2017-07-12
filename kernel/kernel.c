#include "kernel.h"
#include <arc/print.h>

#include "./cpu/idt.h"

void main(void) {
  clear();
  initIDT();
  printk("%s", "ayyyy");
  __asm__ __volatile__("int $2");
  printk("done");
}
