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
       f(); //! ע�⺯���ڲ���̬�����ͷǾ�̬����
            //! ���캯���������������õĴ���
   }

    return 0;
} ///:~
