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
 * ������ó���ȫ��(��̬)������main()��������ǰ���ù��캯��;
 * �����ڲ���̬�����ڵ�һ�ε���ʱ�ŵ��ù��캯��������������
 * ���ã������ڲ���̬���������ʼ�������߶���man()�����˳�
 * ǰ������������
 */
