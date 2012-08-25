//: C11:Refnce.cpp
// Simple C++ references

int *f(int *x) {
    (*x)++;
    return x; // Safe; x is outside this scope
}

int &g(int &x) {
    x++; // Same effect as in f()
    return x; // Safe: outside this scope
}

int &h() {
    int q;
    //! return q; // Error
    static int x;
    return x; // Safe; x lives outside scope
}

int main() {
    int A = 0;

    f(&A); // Ugly (but explicit)
    g(A); // Clean (but hidden)

    return 0;
} ///:~
