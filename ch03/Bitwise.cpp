//: C03:Bitwise.cpp
// Demonstration of bit manipulation

#include <iostream>

using namespace std;

// A macro to print a new-line (saves typing):
#define NL cout << endl
// Notice the trailing ';' is omitted -- this forces the
// programmer to use it and maintain consistent syntax

// This function takes a single byte and displays it
// bit-by-bit. The (1 << i) produces a one in each
// successive bit position; in binary: 00000001, 00000010, etc.
// If this bit bitwise ANDed with val is nonzero, it means
// there was a one in that position in val.
void print_binary(const unsigned char val) {
    for (int i = 7; i >= 0; i--) {
        if (val & (1 << i)) {
            cout << "1";
        } else {
            cout << "0";
        }
    }
}

// Generally, you don't want signs when you are working with
// bytes, so you use an unsigned char.
int main() {
    // An int must be used instead of a char here because the
    // "cin >>" statement will otherwith treate the first digit
    // As a character. By assigning getval to a and b, the value
    // is converted to a single byte (by truncating it)
    unsigned int getval;
    unsigned char a;
    unsigned char b;

    cout << "enter a number between 0 and 255: ";
    cin >> getval;
    a = getval;
    cout << "a in binary: ";
    print_binary(a);
    cout << endl;

    cout << "enter another number between 0 and 255: ";
    cin >> getval;
    b = getval;

    cout << "b in binary: ";
    print_binary(b);
    NL;

    cout << "a | b = ";
    print_binary(a | b);
    NL;

    cout << "a & b = ";
    print_binary(a & b);
    NL;

    cout << " a ^ b = ";
    print_binary(a ^ b);
    NL;

    cout << "~a = ";
    print_binary(~a);
    NL;

    cout << "~b = ";
    print_binary(~b);
    NL;

    unsigned char c = 0x5A; // Interesting bit pattern
    cout << "c in binary: ";
    print_binary(c);
    NL;

    a |= c;
    cout << "a |= c; a = ";
    print_binary(a);
    NL;

    b &= c;
    cout << "b &= c; b = ";
    print_binary(b);
    NL;

    b ^= a;
    cout << "b ^= a; b = ";
    print_binary(b);
    NL;

    return 0;
} ///:~

