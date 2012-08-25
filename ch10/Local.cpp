//: C10:Local.cpp {0}
// Static members & local classes

#include <iostream>

using namespace std;

// Nested class CAN have static data members:
class Outer {
    class Inner {
        static int i; // OK
    };
};

int Outer::Inner::i = 47;

// Local class cannot have static data members:
void f() {
    class Foo {
    public:
    private:
        //! static int i; // Error
        int i; // Non-static OK
        // (How would you define i?)
    } x;
} ///:!
