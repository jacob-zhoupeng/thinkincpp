//: C14:Ninherit.cpp
// Non-inherited functions

#include <fstream>

using namespace std;

ofstream out("ninherit.out");

class Root {
public:
    Root() {
        out << "Root()\n";
    }
    Root(Root &) {
        out << "Root(Root &)\n";
    }
    Root(int) {
        out << "Root(int)\n";
    }
    Root &operator=(const Root &) {
        out << "Root::operator=()\n";
        return *this;
    }
    class Other {
        // Empty class
    };
    operator Other() const {
        out << "Root::operator Other()\n";
        return Other();
    }
    ~Root() {
        out << "~Root()\n";
    }
};

class Derived : public Root {
    // Empty class
};

void f(Root::Other) {
    // Empty body
}

int main() {
    Derived d1; // Default constructor
    Derived d2 = d1; // Copy-constructor
    //! Derived d3(1); // Error: no int constructor
    d1 = d2; // Operator= not inherited
    f(d1); // Type-conversion IS inherited

    return 0;
} ///:~
