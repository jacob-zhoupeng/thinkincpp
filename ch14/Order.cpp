//: C14:Order.cpp
// Constructor/destructor order

#include <fstream>

using namespace std;

ofstream out("order.out");

#define CLASS(ID) class ID { \
public: \
    ID(int) { out << #ID " constructor\n"; } \
    ~ID() { out << #ID " destructor\n"; } \
}

CLASS(Base1);
CLASS(Member1);
CLASS(Member2);
CLASS(Member3);
CLASS(Member4);

class Derived1 : public Base1 {
public:
    //! 先调用基类的构造函数，然后根据成员变量声明的顺序调用构
    //! 造函数，构造函数的调用顺序不受构造函数初始化列表顺序的
    //! 影响
    Derived1(int) : m2(1), m1(2), Base1(3) {
        out << "Derived1 constructor\n";
    }
    //! 析构函数的调用顺序与构造函数的调用顺序恰恰相反
    ~Derived1() {
        out << "Derived1 destructor\n";
    }
private:
    Member1 m1;
    Member2 m2;
};

class Derived2 : public Derived1 {
public:
    Derived2() : m3(1), Derived1(2), m4(3) {
        out << "Derived2 constructor\n";
    }
    ~Derived2() {
        out << "Derived2 destructor\n";
    }
private:
    Member3 m3;
    Member4 m4;
};

int main() {
    Derived2 d2;

    return 0;
} ///:~
