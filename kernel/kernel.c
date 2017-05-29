#include "kernel.h"
#include "../drivers/monitor/monitor.h"

void _start() {
  monitorClear();
  monitorPrintCenter("Ample");
  monitorClear();
  monitorPrint("Ample");
}
