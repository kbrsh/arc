[bits 16]
loadDisk:
  pusha
  push dx

  mov ah, 0x02 ; Read operation
  mov al, 10 ; Read 10 sectors
  mov ch, 0x00 ; Read cylinder 0
  mov dh, 0x00 ; Read head 0
  mov cl, 0x02 ; Read from sector 2

  int 0x13

  pop dx
  popa
  ret
