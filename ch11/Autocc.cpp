//: C11:Autocc.cpp
// Automatic copy-constructor

#include <iostream>
#include <cstring>

using namespace std;

class WithCC { // With copy-constructor
public:
    // Explicit default constructor required:
    WithCC() {
        // Empty body
    }
    //! 提供复制构造函数后，编译器将不再提供默认构造函数
    WithCC(const WithCC &) {
        cout << "WithCC(WithCC &)" << endl;
    }
};

class WoCC { // Without copy-constructor
public:
    WoCC(const char *msg = NULL) {
        memset(buf, 0, bsz);
        if (msg != NULL) {
            strncpy(buf, msg, bsz);
        }
    }

    //! 编译器将提供一个默认复制构造函数，其复制模式是:bitcopy

    void print(const char *msg = NULL) const {
        if (msg != NULL) {
            cout << msg << ": ";
        }
        cout << buf << endl;
    }
private:
    //! C++利用枚举常量作为编译时常量
    enum {
        bsz = 30
    };
    char buf[bsz];
};

class Composite {
public:
    Composite() : wocc("Composite()") {
        // Empty body
    }

    //! 编译器将为Composite提供一个默认复制构造函数，
    //! 该函数将调用每一个成员的(默认/用户自定义)复
    //! 制构造函数。

    void print(const char *msg = NULL) {
        wocc.print(msg);
    }
private:
    WithCC withcc; // Embedded objects
    WoCC wocc;
};

int main() {
    Composite c;

    c.print("contents of c");
    cout << "calling Composite copy-constructor" << endl;

    Composite c2 = c; // Calls copy-constructor
    c2.print("contents of c2");

    return 0;
} ///:~
