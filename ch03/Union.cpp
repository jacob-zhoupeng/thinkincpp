//: C03:Union.cpp
// The size and simple use of a union

#include <iostream>

using namespace std;

union packed { // Declaration similar to a class
    char i;
    short j;
    int k;
    long l;
    float f;
    double d; // The union will be the size of a double,
    // since it's the largest element
}; // Semicolon ends a union, like a class

int main() {
    cout << "sizeof(packed) = " << sizeof(packed) << endl;
    packed X;
    X.i = 'c';
    X.d = 3.14159;

    return 0;
} ///:~
