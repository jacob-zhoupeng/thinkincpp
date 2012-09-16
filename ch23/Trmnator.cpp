//: C23:Trmnator.cpp
// Use of set_terminate()
// Also shows uncaught exceptions
#include <exception>
#include <iostream>
#include <cstdlib>

using namespace std;

void terminator() {
    cout << "I'll be back!" << endl;
    abort();
}

//! 注意定义函数指针变量定义和初始化
void (*old_terminate)() = set_terminate(terminator);

class Botch {
public:
    class Fruit {};
    
    void f() {
        cout << "Botch::f()" << endl;
        throw Fruit();
    }

    ~Botch() {
        throw 'c';
    }
};

int main(int argc, char* argv[]) {
    try {
        Botch b;
        b.f();
        //! 这里编译器在抛出Fruit异常前会插入Botch的析构函数，
        //! 由于析构函数抛出了异常，导致b.f()函数抛出异常语句
        //! 执行不到，异常处理的catch(...)也不能捕获析构函数
        //! 的异常，所以系统调用terinator()函数该函数终止了程序。
        //! 因此，析构函数抛出异常或者引发异常抛出都是设计错误!!!
    } catch (...) {
        cout << "inside catch(...)" << endl;
    }

    return 0;
} ///:~