//: C10:Statdest.cpp
// Static object destructors

#include <fstream>

using namespace std;

ofstream out("statdest.out"); // Trace filebuf

class Obj {
public:
    Obj(char C) : c(C) {
        out << "Obj::Obj() for " << c << endl;
    }
    ~Obj() {
        out << "Obj::~Obj() for " << c <<endl;
    }
private:
    char c; // Identifier
};

Obj A('A'); // Global (static storage)
// Constructor & destructor always called

void f() {
    static Obj B('B');
}

void g() {
    static Obj C('C');
}

int main() {
    out << "inside main()" << endl;
    f(); // Calls static constructor for B
    // g() not called
    out << "leaving main()" << endl;

    return 0;
} ///:~

/**
 * 由输出得出：全局(静态)变量在main()函数调用前调用构造函数;
 * 函数内部静态变量在第一次调用时才调用构造函数，若函数不被
 * 调用，则函数内部静态变量不会初始化。二者都在man()函数退出
 * 前调用析构函数
 */
