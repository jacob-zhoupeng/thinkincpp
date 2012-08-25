//: C03:Union2.cpp
// Unions with constructors/destructor and member functions

#include <iostream>

using namespace std;

union U {
    int i;
    float f;

    U(int a) {
        cout << "Union's constructor with int." << endl;
        i = a;
    }

    U(float b) {
        cout << "Union's construcotr with float." << endl;
        f = b;
    }

    ~U() {
        cout << "Union's destructor..." << endl;
        f = 0;
    }

    int read_int() {
        cout << "read_int(): " << i << endl;
        return i;
    }

    float read_float() {
        cout << "read_float(): " << f << endl;
        return f;
    }
};

int main() {
    U X(12);
    U Y(1.9F);

    X.i = 44;
    X.read_int();
    Y.read_float();

    return 0;
} ///:~
