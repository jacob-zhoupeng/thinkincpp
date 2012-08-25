//: C14:Ccright.cpp
// Correctly synthesizing the CC

#include <iostream>

using namespace std;

class Parent {
public:
    Parent(int I) : i(I) {
        cout << "Parent(int I)\n";
    }
    Parent(const Parent &b) : i(b.i) {
        cout << "Parent(Parent &)\n";
    }
    Parent() : i(0) {
        cout << "Parent()\n";
    }
    friend ostream &operator<<(ostream &os, const Parent &b) {
        return os << "Parent: " << b.i << endl;
    }
private:
    int i;
};

class Member {
public:
    Member(int I) : i(I) {
        cout << "Member(int I)\n";
    }
    Member(const Member &m) : i(m.i) {
        cout << "Member(Member &)\n";
    }
    friend ostream &operator<< (ostream &os, const Member &m) {
        return os << "Member: " << m.i << endl;
    }
private:
    int i;
};

class Child : public Parent {
public:
    Child(int I) : Parent(I), i(I), m(I) {
        cout << "Child(int I)\n";
    }
    friend ostream &operator<<(ostream &os, const Child &d) {
        return os << (Parent &)d << d.m << "Child: " << d.i << endl;
    }
    /**
    //! 错误的复制构造函数
    Child(const Child &d) : i(d.i), m(d.m) {}
    */
    //! Parent(d)会将子类向上转型为基类，然后调用Parent(const Parent &)
    Child(const Child &d) : Parent(d), i(d.i), m(d.m) {
        cout << "Child(Child &)\n";
    }
private:
    int i;
    Member m;
};

int main() {
    Child d(2);

    cout << "calling copy-constructor: " << endl;
    Child d2 = d; // Calls copy-constructor
    cout << "values in d2:\n" << d2;

    return 0;
} ///:~
