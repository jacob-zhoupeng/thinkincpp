//: C05:Usehandl.cpp
// {L} Handle
// Use the Handle class

#include "Handle.h"

int main() {
    Handle u;

    u.initialize();
    u.read();
    u.change(1);
    u.cleanup();

    return 0;
} ///:~
