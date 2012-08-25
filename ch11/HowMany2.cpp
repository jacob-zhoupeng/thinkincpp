//: C11:WowMany2.cpp
// The copy-constructor

#include <fstream>
#include <cstring>

using namespace std;

ofstream out("HowMany2.out");

class HowMany2 {
public:
    HowMany2(const char *ID = NULL) {
        if (ID != NULL) {
            strncpy(id, ID, bufsize);
        } else {
            *id = '\0';
        }
        ++object_count;
        print("HowMany2()");
    }
    // The copy-constructor:
    HowMany2(const HowMany2 &h) {
        strncpy(id, h.id, bufsize);
        strncat(id, " copy", bufsize - strlen(id));
        ++object_count;
        print("HowMany2(HowMany2 &)");
    }
    // Can't be static (printing id):
    void print(const char *msg = NULL) const {
        if (msg != NULL) {
            out << msg << endl;
        }
        out << '\t' << id << ": "
        << "object_count = "
        << object_count << endl;
    }
    ~HowMany2() {
        --object_count;
        print("~HowMany2()");
    }
private:
    //! 枚举类型可以在C++中作为编译常量使用
    enum {
        bufsize = 30
    };
    char id[bufsize]; // Object indentifier
    static int object_count;
};

//! 静态域分配存储空间
int HowMany2::object_count = 0;

// Pass and return BY VALUE:
HowMany2 f(HowMany2 x) {
    x.print("x argument inside f()");
    out << "returning from f()" << endl;

    return x;
}

int main() {
    HowMany2 h("h");
    out << "entering f()" << endl;
    HowMany2 h2 = f(h);
    h2.print("h2 after call to f()");
    out << "call f(), no return value" << endl;
    f(h);
    out << "after call to f()" << endl;

    return 0;
} ///:~
