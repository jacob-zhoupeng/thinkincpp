//: C22:MultipleInheritance2.cpp
// Virtual base classes
#include <iostream>
#include <vector>

#include "../purge.h"

using namespace std;

class Base {
public:
    virtual char* vf() const = 0;
    virtual ~Base() {}
};

class D1 : virtual public Base {
public:
    char* vf() const {
        return "D1";
    }
};

class D2 : virtual public Base {
public:
    char* vf() const {
        return "D2";
    }
};

// MUST explicity disambiguate vf():
class MI : public D1, public D2 {
public:
    char* vf() const {
        return D1::vf();
    }
};

int main(int argc, char* arvg[]) {
    vector<Base*> b;

    b.push_back(new D1);
    b.push_back(new D2);
    b.push_back(new MI); // OK

    for (int i = 0; i < b.size(); i++) {
        cout << b[i]->vf() << endl;
    }

    purge(b);

    return 0;
} ///:~
