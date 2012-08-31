//: C14:Inherit.cpp
// Simple inheritance

#include <iostream>

#include "Useful.h"

using namespace std;

class Y : public X {
public:
    Y() {
        i = 0;
    }
    int change() {
        i = permute(); // Different name call
        return i;
    }
    void set(int I) {
        i = I;
        X::set(I); // Same-name function call
    }
private:
    int i; // Different from X's i
};

int main() {
    cout << "sizeof(X) = " << sizeof(X) << endl;
    cout << "sizeof(Y) = " << sizeof(Y) << endl;

    Y D;
    D.change();
    // X function interface comes through:
    D.read();
    D.permute();
    // Redefined functions hide base version:
    D.set(12);

    return 0;
} ///:~
