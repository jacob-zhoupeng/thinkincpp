//:C12:Opover.cpp
// Operator overloading syntax

#include <iostream>

using namespace std;

class Integer {
public:
    Integer(int I) {
        i = I;
    }
    const Integer operator+(const Integer &rv) const {
        cout << "operator+" << endl;
        return Integer(i + rv.i);
    }
    Integer &operator+=(const Integer &rv) {
        cout << "operator+=" << endl;
        i += rv.i;
        return (*this);
    }
private:
    int i;
};

int main() {
    cout << "built-in types:" << endl;
    int i = 1;
    int j = 2;
    int k = 3;
    k += i + j;

    cout << "user-defined types:" << endl;
    Integer I(1);
    Integer J(2);
    Integer K(3);
    K += I + J;

    return 0;
} ///:~
