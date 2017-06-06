GDT64:

  .Null:
    dq 0

  .Code:
    dq 2136576

  .Data:
    dq 37376

  .Pointer:
    dw $ - GDT32.Null - 1
    dd GDT32.Null

  .codeSeg: equ GDT64.Code - GDT64.Null
  .dataSeg: equ GDT64.Data - GDT64.Null
