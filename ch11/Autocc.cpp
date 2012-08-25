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
    //! �ṩ���ƹ��캯���󣬱������������ṩĬ�Ϲ��캯��
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

    //! ���������ṩһ��Ĭ�ϸ��ƹ��캯�����临��ģʽ��:bitcopy

    void print(const char *msg = NULL) const {
        if (msg != NULL) {
            cout << msg << ": ";
        }
        cout << buf << endl;
    }
private:
    //! C++����ö�ٳ�����Ϊ����ʱ����
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

    //! ��������ΪComposite�ṩһ��Ĭ�ϸ��ƹ��캯����
    //! �ú���������ÿһ����Ա��(Ĭ��/�û��Զ���)��
    //! �ƹ��캯����

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
