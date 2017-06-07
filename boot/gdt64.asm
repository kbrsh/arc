GDT64:

  .Null:
    dq 0

  .Code:
    dw 0
    dw 0
    db 0
    db 10011010b
	  db 00100000b
	  db 0

  .Data:
    dw 0
    dw 0
    db 0
    db 10010010b
	  db 00000000b
	  db 0

  .Pointer:
    dw $ - GDT64.Null - 1
    dd GDT64.Null

  .codeSeg: equ GDT64.Code - GDT64.Null
  .dataSeg: equ GDT64.Data - GDT64.Null
