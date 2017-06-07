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
  mov ebp, 0x11000
  mov esp, ebp

  ; Begin Switching to 64 bits

  ; Setup paging tables
  fill:
    mov dword [0x00010000 + ecx], 0x11000
    or dword [0x00010000 + ecx], 111b
    mov dword [0x00010000 + ecx + 4], 0
    mov dword [0x11000 + ecx], 0x12000
    or dword [0x11000 + ecx], 111b
    mov dword [0x11000 + ecx + 4], 0
    mov dword [0x12000 + ecx], 0x13000
    or dword [0x12000 + ecx], 111b
    mov dword [0x12000 + ecx + 4], 0

    mov eax, (4096/8)
    mul ecx
    mov dword [0x13000 + ecx], eax
    or dword [0x13000 + ecx], 111b
    mov dword [0x13000 + ecx + 4], 0

    add ecx, 8
    cmp ecx, 4096
    jl fill

  ; Setup PAE
  mov eax, cr4
  or eax, 1 << 5
  mov cr4, eax

  ; Use page table in control register
  mov eax, 0x00010000
  mov cr3, eax

  ; Setup Long Mode bit in EFER MSR
  mov ecx, 0xC0000080
  rdmsr
  or eax, 1 << 8
  wrmsr

  ; Enable Paging
  mov eax, cr0
  or eax, 1 << 31
  mov cr0, eax

  lgdt [GDT64.Pointer] ; Load GDT
  jmp GDT64.codeSeg:switch64 ; Perform far jump

[bits 64]
switch64:
  ; Update registers
  mov ax, GDT64.dataSeg
  mov ds, ax
  mov es, ax
  mov ss, ax
  mov fs, ax
  mov gs, ax
  mov ss, ax

  ; After switching to 64 bit long mode, return to main loader and load kernel
  call afterSwitch
