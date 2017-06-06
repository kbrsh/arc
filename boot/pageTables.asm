; Initialize Page Tables
[bits 32]
section .bss

align 4096

PML4:
  resb 4096
PDP:
  resb 4096
PD:
  resb 4096
