//: C03:Static.cpp
// Using static data in a function

#include <iostream>

using namespace std;

void func() {
    static int i = 0; //! Replace is with <code>int i = 0;</code> to see the difference
    cout << "i = " << ++i << endl;
}

int main() {
    for (int x = 0; x < 10; x++) {
        func();
    }

    return 0;
} ///:~
