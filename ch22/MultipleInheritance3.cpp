//: C22:MultipleInheritance3.cpp
// Virtual base initialization
// Virtual base classes must always be
// Initialized by the "most-derived" class
#include <iostream>
#include <vector>

#include "../purge.h"

using namespace std;

class Base {
public:
    Base(int){}
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
    MI() : Base(3) {}

    char* vf() const {
        return D1::vf(); // MUST disambiguate
    }
};

class X : public MI {
public:
    // You must ALWAYS init the virtual base:
    X() : Base(4) {}
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