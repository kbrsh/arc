# Compile Booter
/usr/local/bin/nasm -f bin boot/boot.asm -o boot/boot.bin

# Compile Kernel
i386-elf-gcc -ffreestanding -c kernel/kernel.c -o kernel/kernel.o
i386-elf-gcc -ffreestanding -c util/util.c -o util/util.o
for driverDirectory in drivers/* ; do
    for file in $driverDirectory/* ; do
      if [ ${file: -2} == ".c" ]
      then
        i386-elf-gcc -ffreestanding -c $file -o ${file:0:${#file}-2 }.o
      fi
    done
done
/usr/local/bin/nasm -f elf kernel/wrapper.asm -o kernel/wrapper.o
i386-elf-ld -o kernel/kernel.bin -Ttext 0x1000 kernel/wrapper.o drivers/monitor/monitor.o kernel/kernel.o --oformat binary

# Create Image
cat boot/boot.bin kernel/kernel.bin > dist/ample
