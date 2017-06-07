# Setup Script for new Machines

# Variables for this session
export PREFIX="/usr/local/x86_64elfgcc"
export TARGET=x86_64-elf
export PATH="$PREFIX/bin:$PATH"

# Binutils
mkdir /tmp/src
cd /tmp/src
curl -O http://ftp.gnu.org/gnu/binutils/binutils-2.28.tar.gz
tar xf binutils-2.28.tar.gz
mkdir binutils-build
cd binutils-build
../binutils-2.28/configure --target=$TARGET --enable-interwork --enable-multilib --disable-nls --disable-werror --prefix=$PREFIX 2>&1 | tee configure.log
make all install 2>&1 | tee make.log

# GCC
cd /tmp/src
curl -O http://mirrors-usa.go-parts.com/gcc/releases/gcc-7.1.0/gcc-7.1.0.tar.gz
tar xf gcc-7.1.0.tar.gz
mkdir gcc-build
cd gcc-build
../gcc-7.1.0/configure --target=$TARGET --prefix="$PREFIX" --disable-nls --disable-libssp --enable-languages=c --without-headers
make all-gcc
make all-target-libgcc
make install-gcc
make install-target-libgcc

# Remove Temporary files
cd /tmp
rm -rf src
