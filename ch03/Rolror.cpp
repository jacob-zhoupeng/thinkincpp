//: C03:Rolror.cpp {0}
// Perform left and right rotations

unsigned char ROL(unsigned char val) {
    int highbit;

    if (val & 0x80) { // 0x80 is the high bit only
        highbit = 1;
    } else {
        highbit = 0;
    }

    val <<= 1; // Left shift (bottom bit becomes 0)
    val |= highbit; // Rotate the high bit onto the bottom

    return val; // This becomes the function value
}

unsigned char ROR(unsigned char val) {
    int lowbit;

    if (val & 1) { // Check the low bit
        lowbit = 1;
    } else {
        lowbit = 0;
    }

    val >>= 1; // Right shift by one position
    val |= (lowbit << 7); // Rotate the low bit onto the top

    return val;
} ///:~
