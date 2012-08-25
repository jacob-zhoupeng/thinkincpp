//: C10:Statinit.cpp
// Scope of static initializer

#include <iostream>

using namespace std;

int x = 100;

class WithStatic {
public:
    void print() const {
        cout << "WithStatic::x = " << x << endl;
        cout << "WithStatic::y = " << y << endl;
    }
private:
    static int x; //! 静态成员变量声明，未分配存储空间
    static int y;
};

//! 静态成员变量定义，此时分配存储空间
int WithStatic::x = 1;
int WithStatic::y = x + 1;
// WithStatic::x NOT ::x

int main() {
    WithStatic WS;

    WS.print();

    return 0;
} ///:~


