//: C04:Scoperes.cpp
// Global scope resolution

int A;

void f() {
    // do nothing;
}

struct S {
    int A;
    void f();
};

void S::f() {
    ::f(); // Would be recursive otherwise!
    ::A++; // Select the global A
    A--; // The A at struct scope
}

///:~
