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
 * 请注意:
 * 输出结果可能因您的编译器和平台有差异，影响结果还包括字节对齐要求。
 */