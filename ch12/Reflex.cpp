//: C12:Reflex.pp
// Reflexivity in overloading

#include <iostream>

using namespace std;

class Number {
public:
    Number(int I = 0) {
        i = I;
    }
    const Number operator+(const Number &n) const {
        cout << "调用成员函数:operator+" << endl;
        return Number(i + n.i);
    }
    friend const Number operator-(const Number &, const Number &);
private:
    int i;
};

const Number operator-(const Number &n1, const Number &n2) {
    cout << "调用全局友元函数:operator-" << endl;
    return Number(n1.i - n2.i);
}

int main() {
    Number a(47);
    Number b(11);

    a + b; // OK
    a + 1; // 2nd arg converted to Number
    //! 1 + a; // Wrong!, 1st arg not of type Number
    a - b; // OK
    a - 1; // 2nd arg converted to Number
    1 - a; // 1st arg converted to Number

    return 0;
} ///:~
