//: C15:Addv.cpp
// Adding virtuals in derivation

#include <iostream>

using namespace std;

class Base {
public:
    Base(int I) : i(I) {}
    virtual int value() const {
        return i;
    }
private:
    int i;
};

class Derived : public Base {
public:
    Derived(int I) : Base(I) {}
    int value() const {
        return Base::value() * 2;
    }
    // New virtual function in the derived class:
    virtual int shift(int x) const {
        return Base::value() << x;
    }
};

int main() {
    Base *B[] = {
        new Base(7),
        new Derived(7),
    };

    cout << "B[0]->value() = " << B[0]->value() << endl;
    cout << "B[1]->value() = " << B[1]->value() << endl;
    //! cout << "B[1]->shift(3) = " << B[1]->shift(3) << endl; // Illegal

    return 0;
} ///:~
