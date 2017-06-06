[bits 16]
loadDisk:
  pusha
  push dx

  mov ah, 0x02
  mov al, dh
  mov ch, 0x00
  mov dh, 0x00
  mov cl, 0x02

  int 0x13

  pop dx
  popa
  ret
