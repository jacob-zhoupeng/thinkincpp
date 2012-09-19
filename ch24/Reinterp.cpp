//: C24:Reinterp.cpp
// Reinterpret_cast
// Example depends on VPTR location,
// Which may differ between compilers.
#include <cstring>
#include <fstream>

using namespace std;

ofstream out("reinterp.out");

class X {
public:
    X() {
        memset(a, 0, sz*sizeof(int));
    }

    virtual ~X() {}
    
    virtual void f() {}
    
    // Size of all the data members:
    int membsize() {
        return sizeof(a);
    }

    friend ostream& operator<<(ostream& os, const X& x) {
        for (int i = 0; i < sz; i++) {
            os << x.a[i] << ' ';
        }
        return os;
    }
private:
    enum {
        sz = 5
    };
    int a[sz];
};

int main(int argc, char* argv[]) {
    //! 注意:
    //! 后面的代码是假设编译器将VPTR放在对象内存地址开始处
    //! 您的编译器可能实现不一致.
    
    X x;

    out << x << endl; // Initialized to zeroes
    int* xp = reinterpret_cast<int*>(&x);
    xp[1] = 47;
    out << x << endl; // Oops!

    X x2;
    const int vptr_size = sizeof(X) - x2.membsize();
    long l_addr = reinterpret_cast<long>(&x2);

    // *IF* the VPTR is first in the object:
    l_addr += vptr_size; // Move past VPTR
    xp = reinterpret_cast<int*>(l_addr);
    xp[1] = 47;
    out << x2 << endl;
    
    return 0;
} ///:~
