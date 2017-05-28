gdtNull:
    dd 0x0
    dd 0x0

gdtCode:
    dw 0xffff
    dw 0x0
    db 0x0
    db 10011010b
    db 11001111b
    db 0x0

gdtData:
    dw 0xffff
    dw 0x0
    db 0x0
    db 10010010b
    db 11001111b
    db 0x0

gdtEnd:

gdt:
    dw gdtEnd - gdtNull - 1
    dd gdtNull

codeSeg equ gdtCode - gdtNull
dataSeg equ gdtData - gdtNull
