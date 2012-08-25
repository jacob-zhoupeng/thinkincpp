//: C07:Bitvect.h
// Bit Vector

#ifndef BITVECT_H_INCLUDED
#define BITVECT_H_INCLUDED

class BitVector {
public:
    BitVector(); // Default: 0 size
    // init points to an array of bytes
    // size is measured in bytes
    BitVector(unsigned char *init, int size = 8);
    // binary is a string of 1s and 0s
    BitVector(char *binary);
    ~BitVector();
    void set(int bit);
    void clear(int bit);
    int read(int bit);
    int bits(); // Number of bits in the vector
    void bits(int sz); // Set number of bits
    void print(const char *msg = "");
private:
    unsigned char *bytes;
    int Bits;
    int numBytes;
};

#endif // BITVECT_H_INCLUDED
