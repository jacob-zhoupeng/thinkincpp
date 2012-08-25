//: C13:NoMemory.cpp
// Constructor isn't called
// If new returns 0
//! 注意：这个程序和作者说明的输出结果不一致
//! 可能是编译器没能完全实现标准C++的原因

#include <iostream>
#include <new> // size_t definition

using namespace std;

void my_new_handler() {
    cout << "new handler called" << endl;
}

class NoMemory {
public:
    NoMemory() {
        cout << "NoMemory::NoMemory()" << endl;
    }
    void *operator new(size_t sz) {
        cout << "NoMemory::operator new" << endl;
        return NULL; // "Out of memory"
    }
};

int main() {
    //! 设置new操作失败处理函数
    set_new_handler(my_new_handler);

    NoMemory *nm = new NoMemory;
    cout << "nm = " << nm << endl;
} ///:~
