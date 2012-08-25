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
    static int x; //! ��̬��Ա����������δ����洢�ռ�
    static int y;
};

//! ��̬��Ա�������壬��ʱ����洢�ռ�
int WithStatic::x = 1;
int WithStatic::y = x + 1;
// WithStatic::x NOT ::x

int main() {
    WithStatic WS;

    WS.print();

    return 0;
} ///:~


