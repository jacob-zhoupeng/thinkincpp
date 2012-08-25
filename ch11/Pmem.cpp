//: C11:Pmem.cpp
// Pointers to members

#include <iostream>

using namespace std;

class Widget {
public:
    void f(int);
    void g(int);
    void h(int);
    void i(int);
};

void Widget::h(int arg) {
    cout << "inside Widget::h(int) with " << arg << endl;
}

int main() {
    Widget w;
    Widget *wp = &w;

    // �����Ͷ����ຯ��ָ��pmem
    void (Widget::*pmem)(int) = &Widget::h;

    (w.*pmem)(1);
    (wp->*pmem)(2);

    return 0;
} ///:~
