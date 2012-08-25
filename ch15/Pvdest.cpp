//: C15:Pvdest.cpp
// Pure virtual destructors
// require a function body.

#include <iostream>

using namespace std;

class Base {
public:
    virtual ~Base() {
        cout << "~Base()" << endl;
    }
};

class Derived : public Base {
public:
    ~Derived() {
        cout << "~Derived()" << endl;
    }
};

int main() {
    Base *bp = new Derived(); // Upcast

    delete bp; // Virtual destructor call

    return 0;
}
