//: C22:Mithis.cpp
// MI and the "this" pointer
#include <fstream>

using namespace std;

ofstream out("mithis.out");

class Base1 {
public:
    void printthis1() {
        out << "Base1 this = " << this << endl;
    }
private:
    char c[0x10];
};

class Base2 {
public:
    void printthis2() {
        out << "Base2 this = " << this << endl;
    }
private:
    char c[0x10];
};

class Member1 {
public:
    void printthism1() {
        out << "Member1 this = " << this << endl;
    }
private:
    char c[0x10];
};

class Member2 {
public:
    void printthism2() {
        out << "Member2 this = " << this << endl;
    }
private:
    char c[0x10];
};

class MI : public Base1, public Base2 {
public:
    void printthis() {
        out << "MI this = " << this << endl;

        printthis1();
        printthis2();

        m1.printthism1();
        m2.printthism2();
    }
private:
    Member1 m1;
    Member2 m2;
};

int main(int argc, char* argv[]) {
    MI mi;

    out << "sizeof(mi) = " << hex << sizeof(mi) << " hex" << endl;
    mi.printthis();

    // A second demonstration:
    Base1* b1 = &mi; // Upcast
    Base2* b2 = &mi; // Upcast

    out << "Base 1 pointer = " << b1 << endl;
    out << "Base 2 pointer = " << b2 << endl;

    return 0;
} ///:~