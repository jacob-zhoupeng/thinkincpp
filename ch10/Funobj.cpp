//: C10:Funobj.cpp
// Static objects in functions

#include <iostream>

using namespace std;

class X {
public:
    X(int I = 0) : i(I) { // Default
        cout << "X::X()[" << i << "]" << endl;
    }
    ~X() {
        cout << "X::~X()[" << i << "]" << endl;
    }
private:
    int i;
};

void f() {
    X x1(47);
    static X x2; // Default construcotr required
}

int main() {
   for (int i = 0; i < 10; i++) {
       f(); //! 注意函数内部静态变量和非静态变量
            //! 构造函数和析构函数调用的次数
   }

    return 0;
} ///:~
