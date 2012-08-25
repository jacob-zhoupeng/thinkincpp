//: C13:PlacementNew.cpp
// Placement with operator new
//! 显示指定new关键字分配空间存储地址

#include <cstddef> // For size_t
#include <iostream>

using namespace std;

class X {
public:
    X(int I = 0) {
        i = I;
    }
    ~X() {
        cout << "X::~X() with " << i << endl;
    }
    void *operator new(size_t, void *loc) {
        return loc;
    }
private:
    int i;
};

int main() {
    int arry[10];

    X *xp = new(arry + 5) X(47); // X at location 5
    cout << "arry[5] = " << arry[5] << endl;
    xp->X::~X(); // Explicit destructor call
    // ONLY use with placement!

    return 0;
} ///:~
