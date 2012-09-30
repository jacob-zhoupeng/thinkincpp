//: C26:Memtest.cpp
// {L} Memcheck
// Test of memcheck system
#include "Memcheck.h"

int main() {
    void* v = std::malloc(100);
    delete v;

    int* x = new int;
    std::free(x);

    new double;

    return 0;
} ///:~