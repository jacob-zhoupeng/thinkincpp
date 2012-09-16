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

//! ע�ⶨ�庯��ָ���������ͳ�ʼ��
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
        //! ������������׳�Fruit�쳣ǰ�����Botch������������
        //! �������������׳����쳣������b.f()�����׳��쳣���
        //! ִ�в������쳣�����catch(...)Ҳ���ܲ�����������
        //! ���쳣������ϵͳ����terinator()�����ú�����ֹ�˳���
        //! ��ˣ����������׳��쳣���������쳣�׳�������ƴ���!!!
    } catch (...) {
        cout << "inside catch(...)" << endl;
    }

    return 0;
} ///:~