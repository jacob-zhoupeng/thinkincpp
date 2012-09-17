//: C24:Inhorder.cpp
// Order of constructor calls
#include <iostream>
#include <typeinfo>

using namespace std;

template<int id>
class Announce {
public:
    Announce() {
        cout << typeid(*this).name() << " constructor " << endl;
    }

    ~Announce() {
        cout << typeid(*this).name() << " destructor " << endl;
    }
};

class X : public Announce<0> {
public:
    X() {
        cout << "X::X()" << endl;
    }

    ~X() {
        cout << "X::~X()" << endl;
    }
private:
    Announce<1> m1;
    Announce<2> m2;
};

int main(int argc, char* argv[]) {
    X x;

    return 0;
} ///:~