//: C03:Global2.cpp {0}
// Accessing external global variables

extern int global;
// (The linker resolves the reference)

void foo() {
    global = 47;
} ///:~
