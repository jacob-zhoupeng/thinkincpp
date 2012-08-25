//: C05:Friend.cpp
// Friend allows special access

struct X; // Declaration (incomplete type spec)

struct Y {
    void f(X *);
};

struct X {
public:
    void initialize();

    friend void g(X *, int); // Global friend
    friend void Y::f(X *); // Struct member friend
    friend  struct Z; // Entire struct is a friend
    friend void h();
private:
    int i;
};

void X::initialize() {
    i = 0;
}

// Global function
void g(X *x, int i) {
    x->i = i;
}

void Y::f(X *x) {
    x->i = 47;
}

struct Z {
public:
    void initialize();
    void g(X *x);
private:
    int j;
};

void Z::initialize() {
    j = 99;
}

void Z::g(X *x) {
    x->i += j;
}

// Global function
void h() {
    X x;

    x.i = 100; // Direct data manipulation
}

int main() {
    X x;
    Z z;

    z.g(&x);

    return 0;
} ///:~
