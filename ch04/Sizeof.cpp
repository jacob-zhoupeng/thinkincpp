//: C04:Sizeof.cpp
// Sizes of structs

#include <cstdio>

#include "Lib.h"
#include "Libcpp.h"

using namespace std;

struct A {
    int I[100];
};

struct B {
    void f();
};

void B::f() {
    // do nothing
}

int main() {
    printf("sizeof struct A = %d bytes\n", sizeof(A));
    printf("sizeof struct B = %d bytes\n", sizeof(B));
    printf("sizeof stash in C = %d bytes\n", sizeof(stash));
    printf("sizeof Stash in C++ = %d bytes\n", sizeof(Stash));

    return 0;
} ///:~


