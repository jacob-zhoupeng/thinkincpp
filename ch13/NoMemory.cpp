//: C13:NoMemory.cpp
// Constructor isn't called
// If new returns 0
//! ע�⣺������������˵������������һ��
//! �����Ǳ�����û����ȫʵ�ֱ�׼C++��ԭ��

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
    //! ����new����ʧ�ܴ�����
    set_new_handler(my_new_handler);

    NoMemory *nm = new NoMemory;
    cout << "nm = " << nm << endl;
} ///:~
