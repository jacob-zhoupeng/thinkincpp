//: C23:Catchref.cpp
// Why catch by reference?
#include <iostream>

using namespace std;

class Base {
public:
    virtual void what() {
        cout << "Base" << endl;
    }
};

class Derived : public Base {
public:
    void what() {
        cout << "Derived" << endl;
    }
};

void f() {
    throw Derived();
}

int main(int argc, char* argv[]) {
    try {
        f();
    } catch (Base b) {
        b.what();
    }

    try {
        f();
    } catch (Base& b) {
        b.what();
    }

    return 0;
} ///:~