//: C10:Selfmem.cpp
// Static member of same type
// ensures only one object of this type exists.
// Also referred to as a "singleton" pattern.

#include <iostream>

using namespace std;

class Egg {
public:
    static Egg *instance() {
        return &e;
    }
    int val() {
        return i;
    }
private:
    static Egg e;
    int i;
    Egg(int I) : i(I) {
        // Empty body
    }
};

Egg Egg::e(47);

int main() {
    //! Egg x(1); // Error -- can't create an Egg

    //! You can access the single instance:
    cout << Egg::instance()->val() << endl;

    return 0;
} ///:~
