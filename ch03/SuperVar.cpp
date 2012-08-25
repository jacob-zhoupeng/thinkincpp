//: C03:SuperVar.cpp
// A super-variable

#include <iostream>

using namespace std;

class SuperVar {
public:
    SuperVar(int ii) {
        vartype = integer;
        i = ii;
    }
    SuperVar(float ff) {
        vartype = floating_point;
        f = ff;
    }
    void print();
private:
    enum {
        character,
        integer,
        floating_point
    } vartype; // Define one

    union { // Anonymous union
        char c;
        int i;
        float f;
    };
};

void SuperVar::print() {
    switch (vartype) {
    case character:
        cout << "character: " << c << endl;
        break;
    case integer:
        cout << "integer: " << i << endl;
        break;
    case floating_point:
        cout << "float: " << f << endl;
        break;
    }
}

int main() {
    SuperVar A('c');
    SuperVar B(12);
    SuperVar C(1.44F);

    A.print();
    B.print();
    C.print();

    return 0;
} ///:~
