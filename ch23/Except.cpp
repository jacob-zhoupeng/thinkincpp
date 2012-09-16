//: C23:Except.cpp
// Basic exceptions
// Exception specifications & unexpected()
//! ����ԭ����<except>, ����������д��ʱ
//! ͷ�ļ��������ģ��������ڱ�׼ͳһ���쳣
#include <exception> 
#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

class Up {};
class Fit {};

void g();

void f(int i) throw(Up, Fit) {
    switch (i) {
        case 1:
            throw Up();
        case 2:
            throw Fit();
    }
    g();
}

// void g() {} // Version 1

void g() { // Version 2
    throw 47; // (Can throw built-in types)
}

void my_unexcepted() {
    cout << "unexpected exception thrown";
    exit(1);
}

int main(int argc, char* argv[]) {
    set_unexpected(my_unexcepted);

    // (ignores return value)
    for (int i = 1; i <= 3; i++) {
        try {
            f(i);
        } catch (Up) {
            cout << "Up caught" << endl;
        } catch (Fit) {
            cout << "Fit caught" << endl;
        }
    }

    return 0;
} ///:~