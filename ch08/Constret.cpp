//: C08:Constret.cpp
// Constant return by value
// Result cannot be used as an lvalue

class X {
public:
    X(int I = 0) {
        i = I;
    }
    void modify() {
        i++;
    }
private:
    int i;
};

X f5() {
    return X();
}

const X f6() {
    return X();
}

void f7(X &x) { // Pass by non-const reference
    x.modify();
}

int main() {
    f5() = X(1); // OK -- non-const return value
    f5().modify(); // OK
    //! f7(f5()); // OK /*! ±àÒë²»Í¨¹ý£¿*/

    // Causes compile-time errors:
    //! f6() = X(1);
    //! f6().modify();
    //! f7(f6());

    return 0;
} ///:~
