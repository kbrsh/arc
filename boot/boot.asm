[org 0x7c00]

; Main Boot
[bits 16]
boot:
  mov [bootDrive], dl ; Setup Boot Drive Location

  ; Setup stack
  mov bp, 0x1000
  mov sp, bp

  mov bx, intro ; Store Message in "Base Index" Register
  call print16 ; Print Intro

  call load ; Load Kernel

  call switch ; Switch to Protected Mode

  jmp $ ; Loop

; Load 16 bit printing utility
%include "boot/print16.asm"

; Load 16 bit disk loading utility
%include "boot/loadDisk.asm"

; Load Switcher to Protected Mode
%include "boot/switch.asm"

; Load 64 bit GDT
%include "boot/gdt.asm"

; Load Kernel
[bits 16]
load:
  ; Setup parameters to read from kernel location (0x10000)
  mov bx, 0x1000
  mov es, bx
  mov bx, 0

  mov dl, [bootDrive] ; Read from boot drive

  call loadDisk ; Load from disk

  ret

; After Switching to Long Mode
[bits 64]
afterSwitch:
  call 0x10000 ; Call Kernel

  hlt ; Halt CPU

; Intro Message
intro db "Arc", 0

; Boot Drive Location
bootDrive db 0

times 510 - ($ - $$) db 0 ; Skip over 510 Bytes
dw 0xaa55 ; Let BIOS know disk is Bootable
