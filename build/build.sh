# List of all Object Files
OBJECTFILES="wrapper/wrapper.o"

# Utility to compile a file
function compile {
  FILE=$1
  EXTENSION=${FILE: -2}
  NEWFILE=${FILE:0:${#FILE}-2 }.o

  if [ $EXTENSION == ".c" ]
  then
    i386-elf-gcc -Wall -ffreestanding -c $FILE -o $NEWFILE -I include
  elif [ $EXTENSION == ".asm" ]
  then
    /usr/local/bin/nasm -f elf $FILE -o $NEWFILE
  fi

  OBJECTFILES+=" $NEWFILE"
}

# Utility to compile all C and Assembly files in a directory
function compileAll {
  ALLFILES=$(find $1 -type f -name '*.c' -o -name '*.asm')
  for file in $ALLFILES ; do
      compile $file
  done
}

# Compile Bootloader
/usr/local/bin/nasm -f bin boot/boot.asm -o boot/boot.bin

# Compile Kernel
/usr/local/bin/nasm -f elf wrapper/wrapper.asm -o wrapper/wrapper.o
compileAll drivers
compileAll include/ample
compileAll util
compileAll kernel
i386-elf-ld -o kernel/kernel.bin -Ttext 0x1000 $OBJECTFILES --oformat binary

# Create Image
cat boot/boot.bin kernel/kernel.bin > dist/ample
