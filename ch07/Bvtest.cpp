//: C07:Bvtest.cpp
// {L} Bitvect
// Testing the BitVector class

#include "Bitvect.h"

int main() {
    unsigned char b[] = {
        0x0f, 0xff, 0xf0,
        0xAA, 0x78, 0x11
    };

    BitVector bv1(b, sizeof(b) / sizeof(*b));
    BitVector bv2("10010100111100101010001010010010101");

    bv1.print("bv1 before modification");
    for (int i = 36; i < bv1.bits(); i++) {
        bv1.clear(i);
    }
    bv1.print("bv1 after modification");

    bv2.print("bv2 before modification");
    for (int j = bv2.bits()-10; j < bv2.bits(); j++) {
        bv2.clear(j);
    }
    bv2.set(30);
    bv2.print("bv2 after modification");

    bv2.bits(bv2.bits() / 2);
    bv2.print("bv2 cut in half");
    bv2.bits(bv2.bits() + 10);
    bv2.print("bv2 grown by 10");

    BitVector bv3((unsigned char *) 0);

    return 0;
} ///:~
