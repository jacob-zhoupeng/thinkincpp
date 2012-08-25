//: C03:Specify.cpp
// Demonstrates the use of specifiers
#include <iostream>

using namespace std;

int main() {
    char c;
    unsigned char cu;

    int i;
    unsigned int iu;
    short int is;
    short iis; // Same as short int
    unsigned short int isu;
    unsigned short iisu;
    long int il;
    long iil; // Same as long int
    unsigned long int ilu;
    unsigned long iilu;

    float f;
    double d;
    long double ld;

    cout << "sizeof(char) = " << sizeof(c) << endl;
    cout << "sizeof(unsigned char) = " << sizeof(cu) << endl;

    cout << "sizeof(int) = " << sizeof(i) << endl;
    cout << "sizeof(unsigned int) = " << sizeof(iu) << endl;
    cout << "sizeof(short) = " << sizeof(is) << endl;
    cout << "sizeof(unsigned short) = " << sizeof(isu) << endl;
    cout << "sizeof(long) = " << sizeof(il) << endl;
    cout << "sizeof(unsigned long) = " << sizeof(ilu) << endl;

    cout << "sizeof(float) = " << sizeof(f) << endl;
    cout << "sizeof(double) = " << sizeof(d) << endl;
    cout << "sizeof(long double) = " << sizeof(ld) << endl;

    return 0;
} ///:~
