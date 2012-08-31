//: C13:Malclass.cpp
// Malloc with class objects
// What you'd have to do if not for "new"

#include <cstdlib> // Malloc() & free()
#include <cstring> // Memset()
#include <iostream>

#include "../require.h"

using namespace std;

class Obj {
public:
    void initialize() { // Can't use constructor
        cout << "initializing Obj" << endl;
        i = j = k = 0;
        memset(buf, 0, sz);
    }
    void destroy() { // Can't use destructor
        cout << "destroying Obj" << endl;
    }
private:
    int i;
    int j;
    int k;
    enum {
        sz = 100
    };
    char buf[sz];
};

int main() {
    Obj *obj = (Obj *) malloc(sizeof(Obj));
    require(obj != NULL);

    obj->initialize();
    // ... sometime later:
    obj->destroy();
    free(obj);
} ///:~
