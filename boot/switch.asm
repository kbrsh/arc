; Stay in 16 bits
[bits 16]

; Initialize Switch
switch:
  cli ; Disable Interrupts

  lgdt [GDT32.Pointer] ; Load GDT

  ; Setup control register 0 to enable protected mode
  mov eax, cr0
  or eax, 1
  mov cr0, eax

  jmp GDT32.codeSeg:switch32 ; Jump to Switcher in 32 Bits

; 32 Bit Switch Section
[bits 32]
switch32:
  ; Load registers
  mov ax, GDT32.dataSeg
  mov ds, ax
  mov ss, ax
  mov es, ax
  mov fs, ax
  mov gs, ax

  ; Setup 32 bit stack
  mov ebp, 0x9000
  mov esp, ebp

  ; mov eax, cr4
  ; or eax, 1 << 5
  ; mov cr4, eax

  call afterSwitch
