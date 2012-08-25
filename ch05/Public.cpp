//: C05:Public.cpp {0}
// Public is just like C struct

struct A {
    int i;
    char j;
    float f;

    void foo();
};

void A::foo() {
    // do nothing
}

struct B {
public:
    int i;
    char j;
    float f;

    void foo();
};

void B::foo() {
    // do nothing
}

///:~
