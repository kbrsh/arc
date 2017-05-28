; Stay in 16 bits
[bits 16]

; Initialize Switch
switch:
  cli ; Disable Interrupts
  lgdt [gdt] ; Load GDT

  ; Setup cr0 to be 32 bit
  mov eax, cr0
  or eax, 0x1
  mov cr0, eax

  jmp codeSeg:switch32 ; Jump to Switcher in 32 Bits

; 32 Bit Switch Section
[bits 32]
switch32:
  mov ax, dataSeg
  mov ds, ax
  mov ss, ax
  mov es, ax
  mov fs, ax
  mov gs, ax

  mov ebp, 0x90000
  mov esp, ebp

  call afterSwitch
