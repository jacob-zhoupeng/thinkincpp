//: C15:Slice.cpp
// Object slicing

#include <iostream>

using namespace std;

class Base {
public:
    Base(int I = 0) : i(I) {}
    virtual int sum() const {
        return i;
    }
private:
    int i;
};

class Derived: public Base {
public:
    Derived(int I = 0, int J = 0) : Base(I), j(J) {}
    int sum() const {
        return Base::sum() + j;
    }
private :
    int j;
};

void call(Base b) {
    cout << "sum = " << b.sum() << endl;
}

int main() {
    Base b(10);
    Derived d(10, 47);

    call(b);
    call(d);

    return 0;
} ///:~
