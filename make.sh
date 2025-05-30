#!/bin/bash

# Build without optimizations, since it appears to crash when we use them.
c() {
    echo "Building $1.c..."
    powerpc64-linux-gnu-gcc -mcpu=cell -mbig -m32 -Wl,--oformat=binary,-Ttext="$2" -nostdlib -O0 -o "bin/$1.bin" "src/$1.c"
}

echo "Removing old builds..."
rm -f spawn_game_bolt.{bin,elf,sym}

if [ "$1" == "debug" ]; then
    echo "Generating debug coords/anims.bin"
    python3 src/debug.py
else
    echo "Generating coords.bin and anims.bin..."
    python3 src/make_bins.py
fi

# Build targets
c spawn_game_bolt 10c955c

echo "[DONE]"
