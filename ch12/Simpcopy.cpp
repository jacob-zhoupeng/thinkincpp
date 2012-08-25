//: C12:Simpcopy.cpp
// Simple operator=()

#include <iostream>

using namespace std;

class Value {
public:
    Value(int A = 0, int B = 0, float C = 0.0) {
        a = A;
        b = B;
        c = C;
    }
    Value &operator=(const Value &rv) {
        a = rv.a;
        b = rv.b;
        c = rv.c;
        return *this;
    }
    friend ostream &operator<<(ostream &os, const Value &rv) {
        return os << "a = " << rv.a << ", b = " << rv.b
                << ", c = " << rv.c;
    }
private:
    int a;
    int b;
    float c;
};

int main() {
    Value A;
    Value B(1, 2, 3.3);

    cout << "A: " << A << endl;
    cout << "B: " << B << endl;

    A = B;
    cout << "A after assignment: " << A << endl;

    return 0;
} ///:~
