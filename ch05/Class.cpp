//: C05:Class.cpp {0}
// Similarity of struct and class
// structs default to public, whereas class defaults to private

struct A {
private:
    int i;
    int j;
    int k;
public:
    int f();
    void g();
};

int A::f() {
    return i + j + k;
}

void A::g() {
    i = j = k = 0;
}

// Identical results are produced with:
class B {
    int i;
    int j;
    int k;
public:
    int f();
    void g();
};

int B::f() {
    return i + j + k;
}

void B::g() {
    i = j = k = 0;
}

///:~
