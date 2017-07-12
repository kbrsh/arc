#include "../idt.h"
#include <arc/print.h>

const u8 *exceptionMessages[31] = {
  "Division By Zero",
  "Debug Breakpoint",
  "Non Maskable Interrupt",
  "Breakpoint",
  "Overflow",
  "Bounds",
  "Invalid Opcode",
  "Coprocessor Unavailable",
  "Double Fault",
  "Coprocessor Segment Overrun",
  "Invalid Task State Segment",
  "Segment Not Present",
  "Stack Fault",
  "General Protection Fault",
  "Page Fault",
  "Reserved",
  "x87 Floating-Point Exception",
  "Alignment Check",
  "Machine Check",
  "SIMD Floating-Point Exception",
  "Virtualization Exception",
  "Reserved",
  "Security Exception",
  "Reserved",
  "Triple Fault",
  "Reserved",
  "Reserved",
  "Reserved",
  "Reserved",
  "Reserved",
  "Reserved"
};

void isrHandler(registers_t registers) {
  if(registers.intNum < 32) {

    error("Exception: %s Identifier: %ld", exceptionMessages[registers.intNum], registers.intNum);
  }
}

void setIDTHandler(u32 num, u64 handler) {
  idtHandlers[num].lowOffset = (u16)(handler & 0xFFFF);
  idtHandlers[num].selector = (u16)0x08;
  idtHandlers[num].always0 = (u8)0;
  idtHandlers[num].flags = (u8)0x8E;
  idtHandlers[num].middleOffset = (u16)((handler >> 16) & 0xFFFF);
  idtHandlers[num].highOffset = (u32)((handler >> 32) & 0xFFFFFFFF);
  idtHandlers[num].reserved = (u32)0;
}

void initIDT(void) {
  idtHandlersPointer.limit = 256 * sizeof(idtEntry_t) - 1;
  idtHandlersPointer.base = (u64) &idtHandlers;

  setIDTHandler(0, (u64)isrHandler0);
  setIDTHandler(1, (u64)isrHandler1);
  setIDTHandler(2, (u64)isrHandler2);
  setIDTHandler(3, (u64)isrHandler3);
  setIDTHandler(4, (u64)isrHandler4);
  setIDTHandler(5, (u64)isrHandler5);
  setIDTHandler(6, (u64)isrHandler6);
  setIDTHandler(7, (u64)isrHandler7);
  setIDTHandler(8, (u64)isrHandler8);
  setIDTHandler(9, (u64)isrHandler9);
  setIDTHandler(10, (u64)isrHandler10);
  setIDTHandler(11, (u64)isrHandler11);
  setIDTHandler(12, (u64)isrHandler12);
  setIDTHandler(13, (u64)isrHandler13);
  setIDTHandler(14, (u64)isrHandler14);
  setIDTHandler(15, (u64)isrHandler15);
  setIDTHandler(16, (u64)isrHandler16);
  setIDTHandler(17, (u64)isrHandler17);
  setIDTHandler(18, (u64)isrHandler18);
  setIDTHandler(19, (u64)isrHandler19);
  setIDTHandler(20, (u64)isrHandler20);
  setIDTHandler(21, (u64)isrHandler21);
  setIDTHandler(22, (u64)isrHandler22);
  setIDTHandler(23, (u64)isrHandler23);
  setIDTHandler(24, (u64)isrHandler24);
  setIDTHandler(25, (u64)isrHandler25);
  setIDTHandler(26, (u64)isrHandler26);
  setIDTHandler(27, (u64)isrHandler27);
  setIDTHandler(28, (u64)isrHandler28);
  setIDTHandler(29, (u64)isrHandler29);
  setIDTHandler(30, (u64)isrHandler30);
  setIDTHandler(31, (u64)isrHandler31);

  loadIDT();
}
