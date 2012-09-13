//: C22:MultipleInheritance4.cpp
// "Tying off" virtual bases
// so you don't have to worry about them
// in derived classes
#include <iostream>
#include <vector>

#include "../purge.h"

using namespace std;

class Base {
public:
    // Default constructor removes responsibility:
    Base(int = 0) {}
    virtual char* vf() const = 0;
    virtual ~Base() {}
};

class D1 : virtual public Base {
public:
    D1() : Base(1) {}

    char* vf() const {
        return "D1";
    }
};

class D2 : virtual public Base {
public:
    D2() : Base(2) {}

    char* vf() const {
        return "D2";
    }
};

class MI : public D1, public D2 {
public:
    MI() {} // Calls default constructor for Base

    char* vf() const {
        return D1::vf(); // MUST disambiguate
    }
};

class X : public MI {
public:
    X() {} // Calls default constructor for Base
};

int main(int argc, char* argv[]) {
    vector<Base*> b;

    b.push_back(new D1);
    b.push_back(new D2);
    b.push_back(new MI); // OK
    b.push_back(new X);

    for (int i = 0; i < b.size(); i++) {
        cout << b[i]->vf() << endl;
    }

    purge(b);

    return 0;
} ///:~