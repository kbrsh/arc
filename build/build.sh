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
compileAll include/util
compileAll include/lib
compileAll include/ample
compileAll kernel
i386-elf-ld -o kernel/kernel.bin -Ttext 0x1000 $OBJECTFILES --oformat binary

# Compile into one file
cat boot/boot.bin kernel/kernel.bin > dist/ample

# Cleanup old files
rm -f dist/ample.iso

# Put onto floppy image
dd if=/dev/zero of=dist/ample.img bs=1024 count=1440
dd if=./dist/ample of=dist/ample.img seek=0 conv=notrunc

# Remove binary file
rm -rf dist/ample

# Create temporary iso directory and move image to it
mkdir dist/iso
mv dist/ample.img dist/iso

# Create ISO
mkisofs -quiet -V 'AMPLE' -o dist/ample.iso -b ample.img -hide ample.img dist/iso

# Remove temporary iso directory
rm -rf dist/iso
