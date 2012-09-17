//: C24:Voidrtti.cpp
// RTTI & void pointers
//!!! RTTI does doesn't work with void pointers
#include <iostream>
#include <typeinfo>

using namespace std;

class Stimpy {
public:
    virtual void happy() {}
    virtual void joy() {}
    virtual ~Stimpy();
};

int main(int argc, char* argv[]) {
    void* v = new Stimpy;
    // Error:
    //! Stimpy* s = dynamic_cast<Stimpy*>(v);
    // Error:
    //! cout << typeid(*v).name() << endl;

    return 0;
} ///:~