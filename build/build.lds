OUTPUT_FORMAT("binary")
ENTRY(main)

SECTIONS
{
  .text 0x10000 : AT(0x10000) {
    code = .;
    *(.text)
    *(.rodata)
    . = ALIGN(4096);
  }
  .data : AT(0x10000 + (data - code))
  {
    data = .;
    *(.data)
    . = ALIGN(4096);
  }

  .eh_frame : AT(0x10000 + (ehframe - code))
  {
    ehframe = .;
    *(.eh_frame)
    . = ALIGN(4096);
  }

  .bss : AT(0x10000 + (bss - code))
  {
    bss = .;
    *(.bss)
    *(COMMON)
    . = ALIGN(4096);
  }

  end = .;

  /DISCARD/ :
  {
    *(.comment)
  }
}
