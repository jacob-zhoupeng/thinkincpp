//: C24:Rnest.cpp
// Nesting and RTTI
#include <iostream>
#include <typeinfo>

using namespace std;

class One {
private:
    class Nested {};
    Nested* n;
public:
    One() : n(new Nested()) {}

    ~One() {
        delete n;
    }

    Nested* nested() {
        return n;
    }
};

int main(int argc, char* argv[]) {
    One o;
    cout << typeid(*o.nested()).name() << endl;

    return 0;
} ///:~
