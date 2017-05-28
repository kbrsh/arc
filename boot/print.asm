; 32 Bit Print
[bits 32]

; Video Memory Location
videoMemoryLocation equ 0xb8000
color equ 0x0f

; Print Function
print:
  pusha ; Push registers to stack
  mov edx, videoMemoryLocation ; Move register to video memory location

; Printing Loop
printLoop:
  mov al, [ebx] ; Move pointer to address of character to register
  mov ah, color ; Change Color

  cmp al, 0 ; Check if we've reached the end of the string
  je printEnd ; Jump to End

  mov [edx], ax ; Store character in video memory
  add ebx, 1 ; Move to next character
  add edx, 2 ; Move to next position in video memory

  jmp printLoop ; Loop

; End
printEnd:
  popa
  ret
