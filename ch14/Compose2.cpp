//: C14:Compose2.cpp
// Private embeded objects

#include "Useful.h"

class Y {
public:
    Y() {
        i = 0;
    }
    void f(int I) {
        i = I;
        x.set(I);
    }
    int g() const {
        return i * x.read();
    }
    void permute() {
        x.permute();
    }
private:
    int i;
    X x; // Embeded object
};

int main() {
    Y y;

    y.f(47);
    y.permute();

    return 0;
} ///:~
