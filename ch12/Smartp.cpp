//: C12:Smartp.cpp
// Smart pointer example

#include <iostream>
#include <cstring>

using namespace std;

class Obj {
public:
    void f() {
        cout << i++ << endl;
    }
    void g() {
        cout << j++ << endl;
    }
private:
    static int i;
    static int j;
};

// Static member definitions:
int Obj::i = 47;
int Obj::j = 11;

// Container:
class ObjContainer {
public:
    ObjContainer() {
        index = 0;
        memset(a, 0, sz * sizeof(Obj *));
    }
    void add(Obj *OBJ) {
        if (index >= sz) {
            return;
        }
        a[index++] = OBJ;
    }
    friend class Sp; // 友元类
private:
    enum {
        sz = 100
    };
    Obj *a[sz];
    int index;
};

// Iterator:
class Sp {
public:
    Sp(ObjContainer *objc) {
        index = 0;
        oc = objc;
    }

    // Return value indicates end of list:
    int operator++() { // Prefix
        if (index >= oc->sz) {
            return 0;
        }
        if (oc->a[++index] == NULL) {
            return 0;
        }
        return 1;
    }
    int operator++(int) { // Postfix
        return operator++(); // Use prefix version
    }

    Obj *operator->() const {
        if (oc->a[index] != NULL) {
            return oc->a[index];
        }
        static Obj dummy; // Null Object模式
        return &dummy;
    }
private:
    ObjContainer *oc;
    int index;
};

int main() {
    const int sz = 40; //! 原书代码可能有误：const sz = 10;
    Obj o[sz];
    ObjContainer oc;

    for (int i = 0; i < sz; i++) {
        oc.add(&o[i]); // Fill it up
    }

    Sp sp(&oc); // Create an iterator

    do {
        sp->f(); // Smart pointer calls
        sp->g();
    } while (sp++ != 0);
} ///:~
