//: C14:Combined.cpp
// Inheritance & COMPOSITIONFORM

#include <iostream>

using namespace std;

class A {
public:
    A(int I) {
        cout << "A::A()" << endl;
        i = I;
    }
    ~A() {
        cout << "A::~A()" << endl;
    }
    void f() const {
        // Empty body
    }
private:
    int i;
};

class B {
public:
    B(int I) {
        cout << "B::B()" << endl;
        i = I;
    }
    ~B() {
        cout << "B::~B()" << endl;
    }
    void f() const {
        // Empty body
    }
private:
    int i;
};

class C : public B {
public:
    C(int I) : B(I), a(I) {
        cout << "C::C()" << endl;
        // Empty body
    }
    ~C() {
        // Calls ~A() and ~B()
        cout << "C::~C()" << endl;
    }
    void f() const {
        // Redefinition
        a.f();
        B::f();
    }
private:
    A a;
};

int main() {
    C c(47);

    return 0;
} ///:~
