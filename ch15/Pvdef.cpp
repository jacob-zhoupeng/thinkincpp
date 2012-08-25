//: C15:Pvdef.cpp
// Pure virtual base definition
//! 这个CPP编译不通过，原书程序有错？

#include <iostream>

using namespace std;

class Base {
public:
    virtual void v() const = 0;
    // In situ:
    virtual void f() const = 0 {
        cout << "Base::f()\n";
    }
};

void Base::v() const {
    cout << "Base::v()\n";
}

class D : public Base {
public:
    // Use the common Base code:
    void v() const {
        Base::v();
    }
    void f() const {
        Base::f();
    }
};

int main() {
    D d;

    d.v();
    d.f();

    return 0;
} ///:~
