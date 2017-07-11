%macro pushAll 0
  push rax
  push rcx
  push rdx
  push rbx
  push rsp
  push rbp
  push rsi
  push rdi
%endmacro

%macro popAll 0
  pop rdi
  pop rsi
  pop rbp
  pop rsp
  pop rbx
  pop rdx
  pop rcx
  pop rax
%endmacro

extern isrHandler
isrHandlerWrapper:
  mov rcx, 10
  pushAll
  mov ax, ds
  push rax

  call isrHandler

  pop rax

  popAll
  add rsp, 16
  sti
  iretq

global loadIDT
extern idtHandlersPointer
loadIDT:
  lidt [idtHandlersPointer]
  ret

global isrHandler0
global isrHandler1
global isrHandler2
global isrHandler3
global isrHandler4
global isrHandler5
global isrHandler6
global isrHandler7
global isrHandler8
global isrHandler9
global isrHandler10
global isrHandler11
global isrHandler12
global isrHandler13
global isrHandler14
global isrHandler15
global isrHandler16
global isrHandler17
global isrHandler18
global isrHandler19
global isrHandler20
global isrHandler21
global isrHandler22
global isrHandler23
global isrHandler24
global isrHandler25
global isrHandler26
global isrHandler27
global isrHandler28
global isrHandler29
global isrHandler30
global isrHandler31

isrHandler0:
  cli
  push byte 0
  push byte 0
  jmp isrHandlerWrapper

isrHandler1:
  cli
  push byte 0
  push byte 1
  jmp isrHandlerWrapper

isrHandler2:
  cli
  push byte 0
  push byte 2
  jmp isrHandlerWrapper

isrHandler3:
  cli
  push byte 0
  push byte 3
  jmp isrHandlerWrapper

isrHandler4:
  cli
  push byte 0
  push byte 4
  jmp isrHandlerWrapper

isrHandler5:
  cli
  push byte 0
  push byte 5
  jmp isrHandlerWrapper

isrHandler6:
  cli
  push byte 0
  push byte 6
  jmp isrHandlerWrapper

isrHandler7:
  cli
  push byte 0
  push byte 7
  jmp isrHandlerWrapper

isrHandler8:
  cli
  push byte 8
  jmp isrHandlerWrapper

isrHandler9:
  cli
  push byte 0
  push byte 9
  jmp isrHandlerWrapper

isrHandler10:
  cli
  push byte 10
  jmp isrHandlerWrapper

isrHandler11:
  cli
  push byte 11
  jmp isrHandlerWrapper

isrHandler12:
  cli
  push byte 12
  jmp isrHandlerWrapper

isrHandler13:
  cli
  push byte 13
  jmp isrHandlerWrapper

isrHandler14:
  cli
  push byte 14
  jmp isrHandlerWrapper

isrHandler15:
  cli
  push byte 0
  push byte 15
  jmp isrHandlerWrapper

isrHandler16:
  cli
  push byte 0
  push byte 16
  jmp isrHandlerWrapper

isrHandler17:
  cli
  push byte 0
  push byte 17
  jmp isrHandlerWrapper

isrHandler18:
  cli
  push byte 0
  push byte 18
  jmp isrHandlerWrapper

isrHandler19:
  cli
  push byte 0
  push byte 19
  jmp isrHandlerWrapper

isrHandler20:
  cli
  push byte 0
  push byte 20
  jmp isrHandlerWrapper

isrHandler21:
  cli
  push byte 0
  push byte 21
  jmp isrHandlerWrapper

isrHandler22:
  cli
  push byte 0
  push byte 22
  jmp isrHandlerWrapper

isrHandler23:
  cli
  push byte 0
  push byte 23
  jmp isrHandlerWrapper

isrHandler24:
  cli
  push byte 0
  push byte 24
  jmp isrHandlerWrapper

isrHandler25:
  cli
  push byte 0
  push byte 25
  jmp isrHandlerWrapper

isrHandler26:
  cli
  push byte 0
  push byte 26
  jmp isrHandlerWrapper

isrHandler27:
  cli
  push byte 0
  push byte 27
  jmp isrHandlerWrapper

isrHandler28:
  cli
  push byte 0
  push byte 28
  jmp isrHandlerWrapper

isrHandler29:
  cli
  push byte 0
  push byte 29
  jmp isrHandlerWrapper

isrHandler30:
  cli
  push byte 0
  push byte 30
  jmp isrHandlerWrapper

isrHandler31:
  cli
  push byte 0
  push byte 31
  jmp isrHandlerWrapper
