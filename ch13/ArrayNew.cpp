//: C13:ArrayNew.cpp
// Operator new for arrays

#include <new> // Size_t definition
#include <fstream>

using namespace std;

ofstream trace("ArrayNew.out");

class Widget {
public:
    Widget() {
        trace << "*";
    }
    ~Widget() {
        trace << "~";
    }
    void *operator new(size_t sz) {
        trace << "Widget::new: " << sz
            << " bytes" << endl;
        return ::new char[sz];
    }
    void operator delete(void *p) {
        trace << "Widget::delete" << endl;
        ::delete[] p;
    }
    void *operator new[](size_t sz) {
        trace << "Widget::new[] " << sz
            << " bytes" << endl;
        return ::new char[sz];
    }
    void operator delete[](void *p) {
        trace << "Widget::delete[]" << endl;
        ::delete[] p;
    }
private:
    int i[10];
};

int main() {
    trace << "new Widget" << endl;
    Widget *w = new Widget;
    trace << "\ndelete Widget" << endl;
    delete w;

    trace << "\nnew Widget[25]" << endl;
    Widget *wa = new Widget[25];
    trace << "\ndelete[] Widget" << endl;
    delete[] wa;

    return 0;
} ///:~
