//: C22:Overhead.cpp
// Virtual Base class overhead
#include <fstream>

using namespace std;

ofstream out("overhead.out");

class Base {
public:
    virtual void f() const {}
    virtual ~Base() {}
};

class NonVirtualInheritance : public Base {};

class VirtualInheritance : virtual public Base {};

class VirtualInheritance2 : virtual public Base {};

class MI : public VirtualInheritance, public VirtualInheritance2 {};

#define WRITE(arg) \
    out << #arg << "=" << arg << endl;

int main(int argc, char* argv[]) {
    Base b;
    WRITE(sizeof(b));
    
    NonVirtualInheritance nonv_inheritance;
    WRITE(sizeof(nonv_inheritance));

    VirtualInheritance v_inheritance;
    WRITE(sizeof(v_inheritance));

    MI mi;
    WRITE(sizeof(mi));

    return 0;
} ///:~

/**
 * ��ע��:
 * ���������������ı�������ƽ̨�в��죬Ӱ�����������ֽڶ���Ҫ��
 */