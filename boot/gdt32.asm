GDT32:

  .Null:
    dq 0

  .Code:
    dw 0xffff
    dw 0
    db 0
    db 0x9a
	  db 11001111b
	  db 0

  .Data:
    dw 0xffff
    dw 0x0
    db 0x0
    db 0x92
	  db 11001111b
	  db 0

  .Pointer:
    dw $ - GDT32.Null - 1
    dd GDT32.Null

  .codeSeg equ GDT32.Code - GDT32.Null
  .dataSeg equ GDT32.Data - GDT32.Null
