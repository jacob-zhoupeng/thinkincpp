//: C11:Pmem2.cpp
// Pointers to members

#include <iostream>

using namespace std;

class Widget {
public:
    Widget() {
        fptr[0] = &Widget::f; // Full spec required
        fptr[1] = &Widget::g;
        fptr[2] = &Widget::h;
        fptr[3] = &Widget::i;
    }
    void select(int I, int J) {
        if (I < 0 || I >= count) {
            return;
        }
        (/*(Widget *)*/this->*fptr[I])(J); //! this强调对象本身
    }
    int Count() {
        return count;
    }
private:
    void f(int arg) const {
        cout << "Widget::f() with: " << arg << endl;
    }
    void g(int arg) const {
        cout << "Widget::g() with: " << arg << endl;
    }
    void h(int arg) const {
        cout << "Widget::h() with: " << arg << endl;
    }
    void i(int arg) const {
        cout << "Widget::i() with: " << arg << endl;
    }
    enum {
        count = 4
    };
    // 声明类函数指针数组
    void (Widget::*fptr[count])(int) const;
};

int main() {
    Widget w;

    for (int i = 0; i < w.Count(); i++) {
        w.select(i, 47);
    }

    return 0;
} ///:~
