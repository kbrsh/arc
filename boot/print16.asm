; 16 Bit Print
[bits 16]

; Print Function
print16:
  pusha ; Push registers to stack
  mov ah, 0x0e ; Switch to TTY Mode

; Printing Loop
print16Loop:
  mov al, [bx] ; Set register to current character pointer to memory
  cmp al, 0 ; Compare index to 0 to see if string ended
  je print16End ; If string ended, exit loop

  int 0x10 ; Interupt and Print

  add bx, 1 ; Increment Counter
  jmp print16Loop ; Repeat

; End
print16End:
  popa ; Pop all registers in stack
  ret ; Return
