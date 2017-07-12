#include "kernel.h"
#include <arc/print.h>

#include "./cpu/idt.h"

void main(void) {
  clear();
  initIDT();
}
