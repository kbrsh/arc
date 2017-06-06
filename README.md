# Ample

Minimalistic Kernel for Learning

### Todo

- [ ] Bootloader
  - [ ] Real Mode
  - [ ] Protected Mode
  - [ ] Long Mode
  - [ ] Give control to Kernel
- [ ] Includes
  - [ ] Ample
    - [ ] Printing Utilities (`<ample/print.h>` - `printk`)
  - [ ] LibC
    - [ ] Stdio
      - [ ] `sprintf` - format string
    - [ ] Stdlib
      - [ ] `malloc` - allocate memory
      - [ ] `free` - free memory
    - [ ] String
      - [ ] `strlen` - give length of a string
    - [ ] Stdarg
      - [ ] Variadic Functions (`va_start`, `va_arg`)
- [ ] Kernel
  - [ ] Basic console
    - [ ] Logs
    - [ ] Initialize keyboard input
  - [ ] User Mode
    - [ ] Switch to user mode
    - [ ] Virtual File System (VFS)
    - [ ] Stdin
    - [ ] Stdout
