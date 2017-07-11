#include "kernel.h"
#include <arc/print.h>

#include "./cpu/idt.h"

void _start(void) {
  clear();
  initIDT();
}
