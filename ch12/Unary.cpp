//: C12:Unary.cpp
// Overloading unary operators

#include <iostream>

using namespace std;

class Integer {
public:
    Integer(long I = 0) : i(I) {
        // Empty body
    }
    // No side effects takes const & argument:
    friend const Integer &operator+(const Integer &a);
    friend const Integer operator-(const Integer &a);
    friend const Integer operator~(const Integer &a);
    friend Integer *operator&(Integer &a);
    friend int operator!(const Integer &a);

    // Side effects don't take const &argument:
    // Prefix:
    friend const Integer &operator++(Integer &a);
    // Postfix:
    friend const Integer operator++(Integer &a, int);
    // Prefix:
    friend const Integer &operator--(Integer &a);
    // Postfix:
    friend const Integer operator--(Integer &a, int);
private:
    long i;
    Integer *This() {
        return this;
    }
};

// Global operators:
const Integer &operator+(const Integer &a) {
    cout << "+Integer\n";
    return a; // Unary + has no effect
}

const Integer operator-(const Integer &a) {
    cout << "-Integer\n";
    return Integer(-a.i);
}

const Integer operator~(const Integer &a) {
    cout << "~Integer\n";
    return Integer(~a.i);
}

Integer *operator&(Integer &a) {
    cout << "&Integer\n";
    return a.This(); // &a is recursive!
}

int operator!(const Integer &a) {
    cout << "!Integer\n";
    return !a.i;
}

// Prefix: return incremented value
const Integer &operator++(Integer &a) {
    cout << "++Integer\n";
    a.i++;
    return a;
}

// Postfix; return the value before increment:
const Integer operator++(Integer &a, int) {
    cout << "Integer++\n";
    Integer r(a.i);
    a.i++;
    return a;
}

// Prefix: return decremented value
const Integer &operator--(Integer &a) {
    cout << "--Integer\n";
    a.i--;
    return a;
}

// Postfix: return the before decrement:
const Integer operator--(Integer &a, int) {
    cout << "Integer--\n";
    Integer r(a.i);
    a.i--;
    return r;
}

void f(Integer a) {
    +a;
    -a;
    ~a;
    Integer *ip = &a;
    !a;
    ++a;
    a++;
    --a;
    a--;
}

// Member operators (implicit "this"):
class Byte {
public:
    Byte(unsigned char B = 0) : b(B) {
        // Empty body
    }

    // No side effects: const member function:
    const Byte &operator+() const {
        cout << "+Byte\n";
        return *this;
    }
    const Byte operator-() const {
        cout << "-Byte\n";
        return Byte(-b);
    }
    const Byte operator~() const {
        cout << "~Byte\n";
        return Byte(~b);
    }
    Byte operator!() const {
        cout << "!Byte\n";
        return Byte(!b);
    }
    Byte *operator&() {
        cout << "&Byte\n";
        return this;
    }

    // Side effects: non-const member function:
    const Byte &operator++() { // Prefix
        cout << "++Byte\n";
        b++;
        return *this;
    }
    const Byte operator++(int) { // Postfix
        cout << "Byte++\n";
        Byte before(b);
        b++;
        return before;
    }
    const Byte &operator--() { // Prefix
        cout << "--Byte\n";
        --b;
        return *this;
    }
    const Byte operator--(int) { // Postfix
        cout << "Byte--\n";
        Byte before(b);
        --b;
        return before;
    }
private:
    unsigned char b;
};

void g(Byte b) {
    +b;
    -b;
    ~b;
    Byte *bp = &b;
    !b;
    ++b;
    b++;
    --b;
    b--;
}

int main() {
    Integer a;
    f(a);

    Byte b;
    g(b);

    return 0;
} ///:~
