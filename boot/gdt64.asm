GDT64:

  .Null:
    dw 0
    dw 0
    db 0
    db 0
    db 0
    db 0

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
    dw $ - GDT64 - 1
    dq GDT64

  .codeSeg: equ GDT64.Code - GDT64.Null
  .dataSeg: equ GDT64.Data - GDT64.Null
