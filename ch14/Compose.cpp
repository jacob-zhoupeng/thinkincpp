//: C14:Compose.cpp
// Reuse code with composition

#include "Useful.h"

class Y {
public:
    X x; // Embeded object
    Y () {
        i = 0;
    }
    void f(int I) {
        i = I;
    }
    int g() const {
        return i;
    }
private:
    int i;
};

int main() {
    Y y;

    y.f(47);
    y.x.set(37); // Access the embeded object

    return 0;
} ///:~
