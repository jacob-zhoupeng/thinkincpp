//: C12:Autoeq.cpp
// Automatic operator=()

#include <iostream>

using namespace std;

class Bar {
public:
    Bar &operator=(const Bar &) {
        cout << "inside Bar::operator=()" << endl;
        return *this;
    }
};

class Foo {
    Bar b;
};

int main() {
    Foo a, b;
    a = b; // Prints: "inside Bar::operator=()"

    return 0;
} ///:~
