//: C07:Bitvect.cpp {0}
// BitVector Implementation

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits> // CHAR_BIT = # bits in char

#include "../require.h"
#include "Bitvect.h"

using namespace std;

// A byte with the high bit set:
const unsigned char highbit = 1 << (CHAR_BIT - 1);

BitVector::BitVector() {
    numBytes = 0;
    Bits = 0;
    bytes = 0;
}

// Notice default args are not duplicated:
BitVector::BitVector(unsigned char *init, int size) {
    numBytes = size;
    Bits = numBytes * CHAR_BIT;
    bytes = (unsigned char *) calloc(numBytes, 1);
    require(bytes != NULL);
    if (init == NULL) {
        return; // Default to all 0
    }
    // Translate from bytes into bit sequence:
    for (int index = 0; index < numBytes; index++) {
        for (int offset = 0; offset < CHAR_BIT; offset++) {
            if (init[index] & (highbit >> offset)) {
                set(index * CHAR_BIT + offset);
            }
        }
    }
}

BitVector::BitVector(char *binary) {
    Bits = strlen(binary);
    numBytes = Bits / CHAR_BIT;
    // If there's a remainder, add 1 byte:
    if (Bits % CHAR_BIT) {
        numBytes++;
    }
    bytes = (unsigned char *) calloc(numBytes, 1);
    require(bytes != NULL);
    for (int i = 0; i < Bits; i++) {
        if (binary[i] == '1') {
            set(i);
        }
    }
}

BitVector::~BitVector() {
    free(bytes);
}

void BitVector::set(int bit) {
    require(bit >= 0 && bit < Bits);
    int index = bit / CHAR_BIT;
    int offset = bit % CHAR_BIT;
    unsigned char mask = (1 << offset);
    bytes[index] |= mask;
}

int BitVector::read(int bit) {
    require(bit >= 0 && bit < Bits);
    int index = bit / CHAR_BIT;
    int offset = bit % CHAR_BIT;

    return (bytes[index] >> offset) & 1;
}

void BitVector::clear(int bit) {
    require(bit >= 0 && bit < Bits);
    int index = bit / CHAR_BIT;
    int offset = bit % CHAR_BIT;
    unsigned char mask = ~(1 << offset);
    bytes[index] &= mask;
}

int BitVector::bits() {
    return Bits;
}

void BitVector::bits(int size) {
    int oldsize = Bits;
    Bits = size;
    numBytes = Bits / CHAR_BIT;
    // If there's a remainder, add 1 byte:
    if (Bits % CHAR_BIT) {
        numBytes++;
    }
    void *v = realloc(bytes, numBytes);
    require(v != NULL);
    bytes = (unsigned char *) v;
    for (int i = oldsize; i < Bits; i++) {
        clear(i); // Erase additional bits
    }
}

void BitVector::print(const char *msg) {
    puts(msg);
    for (int i = 0; i < Bits; i++) {
        if (read(i) != 0) {
            putchar('1');
        } else {
            putchar('0');
        }
        // Format into byte blocks:
        if ((i + 1) % CHAR_BIT == 0) {
            putchar(' ');
        }
    }

    putchar('\n');
} ///:~
