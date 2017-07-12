#include "kernel.h"
#include "./cpu/idt.h"

#include <arc/print.h>

void main(void) {
  clear();
  initIDT();
}
