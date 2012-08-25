//: C15:Sizes.cpp
// Object sizes vs. virtual funcs

#include <iostream>

using namespace std;

class NoVirtual {
public:
    void x() const {}
    int i() const {
        return 1;
    }
private:
    int a;
};

class OneVirtual {
public:
    virtual void x() const {}
    int i() const {
        return 1;
    }
private:
    int a;
};

class TwoVirtuals {
public:
    virtual void x() const {}
    virtual int i() const {
        return 1;
    }
private:
    int a;
};

int main() {
    cout << "int: " << sizeof(int) << endl;
    cout << "NoVirtual: " << sizeof(NoVirtual) << endl;
    cout << "void* :" << sizeof(void *) << endl;
    cout << "OneVirtual: " << sizeof(OneVirtual) << endl;
    cout << "TwoVirtuals: " << sizeof(TwoVirtuals) << endl;

    return 0;
} ///:~
