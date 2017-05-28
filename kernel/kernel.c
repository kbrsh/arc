#include "kernel.h"
#include "../drivers/monitor/monitor.h"

void _start() {
  monitorClear();
  monitorPrint("Ample OS");
}
