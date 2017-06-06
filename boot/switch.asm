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

  ; Begin Switching to 64 bits

  ; Setup paging table

  ; Point first section of PDP to PML4
  mov eax, PDP
  or eax, 0b11
  mov dword [PML4], eax

  ; Point first section of PD to PDP
  mov eax, PD
  or eax, 0b11
  mov dword [PDP], eax

  ; Loop and fill table
  mov ecx, 0
  fillPageTable:
    mov eax, 0x200000
    mul ecx
    or eax, 0b10000011
    mov [PD + ecx * 8], eax

    inc ecx
    cmp ecx, 512
    jne fillPageTable

  ; Use page table in control register
  mov eax, PML4
  mov cr3, eax

  ; Setup PAE
  mov eax, cr4
  or eax, 1 << 5
  mov cr4, eax

  ; Setup Long Mode bit in EFER MSR
  mov ecx, 0xC0000080
  rdmsr
  or eax, 1 << 8
  wrmsr

  ; Enable Paging
  mov eax, cr0
  or eax, 1 << 31
  mov cr0, eax

  lgdt [GDT64.Pointer]
  jmp GDT64.codeSeg:switch64 ; Perform far jump

[bits 64]
switch64:
  ; After switching to 64 bit long mode, return to main loader and load kernel
  call afterSwitch
