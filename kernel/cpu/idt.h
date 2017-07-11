#ifndef IDT_H
#define IDT_H

#include <util/types.h>

typedef struct {
  u16 lowOffset;
  u16 selector;
  u8 always0;
  u8 flags;
  u16 middleOffset;
  u32 highOffset;
  u32 reserved;
} __attribute__((packed)) idtEntry_t;

typedef struct {
  u16 limit;
  u64 base;
} __attribute__((packed)) idtHandlersPointer_t;

typedef struct {
  u64 ds;
  u64 rdi, rsi, rbp, rsp, rbx, rdx, rcx, rax;
  u64 intNum, errorCode;
  u64 rip, cs, eflags, useresp, ss;
} registers_t;

idtEntry_t idtHandlers[256];
idtHandlersPointer_t idtHandlersPointer;

extern void isrHandler(registers_t registers);

extern void isrHandler0(void);
extern void isrHandler1(void);
extern void isrHandler2(void);
extern void isrHandler3(void);
extern void isrHandler4(void);
extern void isrHandler5(void);
extern void isrHandler6(void);
extern void isrHandler7(void);
extern void isrHandler8(void);
extern void isrHandler9(void);
extern void isrHandler10(void);
extern void isrHandler11(void);
extern void isrHandler12(void);
extern void isrHandler13(void);
extern void isrHandler14(void);
extern void isrHandler15(void);
extern void isrHandler16(void);
extern void isrHandler17(void);
extern void isrHandler18(void);
extern void isrHandler19(void);
extern void isrHandler20(void);
extern void isrHandler21(void);
extern void isrHandler22(void);
extern void isrHandler23(void);
extern void isrHandler24(void);
extern void isrHandler25(void);
extern void isrHandler26(void);
extern void isrHandler27(void);
extern void isrHandler28(void);
extern void isrHandler29(void);
extern void isrHandler30(void);
extern void isrHandler31(void);

extern void loadIDT(void);

void setIDTHandler(int num, u64 handler);
void initIDT(void);

#endif
