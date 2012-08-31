//: C12:Binary.cpp
// Overloading binary operators

#include <fstream>

#include "../require.h"

using namespace std;

ofstream out("binary.out");

class Integer { // Combine this with UNARY.CPP
public:
    Integer(long I = 0) : i(I) {
        // Empty body
    }

    // Operators that create new, modified value:
    friend const Integer operator+(const Integer &left, const Integer &right);
    friend const Integer operator-(const Integer &left, const Integer &fight);
    friend const Integer operator*(const Integer &left, const Integer &right);
    friend const Integer operator/(const Integer &left, const Integer &right);
    friend const Integer operator%(const Integer &left, const Integer &right);
    friend const Integer operator^(const Integer &left, const Integer &right);
    friend const Integer operator&(const Integer &left, const Integer &right);
    friend const Integer operator|(const Integer &left, const Integer &right);
    friend const Integer operator<<(const Integer &left, const Integer &right);
    friend const Integer operator>>(const Integer &left, const Integer &right);

    // Assignments modify & return lvalue:
    friend Integer &operator+=(Integer &left, const Integer &right);
    friend Integer &operator-=(Integer &left, const Integer &right);
    friend Integer &operator*=(Integer &left, const Integer &right);
    friend Integer &operator/=(Integer &left, const Integer &right);
    friend Integer &operator%=(Integer &left, const Integer &right);
    friend Integer &operator^=(Integer &left, const Integer &right);
    friend Integer &operator&=(Integer &left, const Integer &right);
    friend Integer &operator|=(Integer &left, const Integer &right);
    friend Integer &operator<<=(Integer &left, const Integer &right);
    friend Integer &operator>>=(Integer &left, const Integer &right);

    // Conditional operators return true/false:
    friend int operator==(const Integer &left, const Integer &right);
    friend int operator!=(const Integer &left, const Integer &right);
    friend int operator<(const Integer &left, const Integer &right);
    friend int operator>(const Integer &left, const Integer &right);
    friend int operator<=(const Integer &left, const Integer &right);
    friend int operator>=(const Integer &left, const Integer &right);
    friend int operator&&(const Integer &left, const Integer &right);
    friend int operator||(const Integer &left, const Integer &right);

    // Write the contents to an ostream:
    void print(ostream &os) const {
        os << i;
    }
private:
    long i;
};

const Integer operator+(const Integer &left, const Integer &right) {
    return Integer(left.i + right.i);
}

const Integer operator-(const Integer &left, const Integer &right) {
    return Integer(left.i - right.i);
}

const Integer operator*(const Integer &left, const Integer &right) {
    return Integer(left.i * right.i);
}

const Integer operator/(const Integer &left, const Integer &right) {
    require(right.i != 0, "divide by zero");
    return Integer(left.i / right.i);
}

const Integer operator%(const Integer &left, const Integer &right) {
    require(right.i != 0, "modulo by zero");
    return Integer(left.i % right.i);
}

const Integer operator^(const Integer &left, const Integer &right) {
    return Integer(left.i ^ right.i);
}

const Integer operator&(const Integer &left, const Integer &right) {
    return Integer(left.i & right.i);
}

const Integer operator|(const Integer &left, const Integer &right) {
    return Integer(left.i | right.i);
}

const Integer operator<<(const Integer &left, const Integer &right) {
    return Integer(left.i << right.i);
}

const Integer operator>>(const Integer &left, const Integer &right) {
    return Integer(left.i >> right.i);
}

// Assignments modify & return lvalue:
Integer &operator+=(Integer &left, const Integer &right) {
    if (&left == &right) {
        /* self-assignment */
    }
    left.i += right.i;
    return left;
}

Integer &operator-=(Integer &left, const Integer &right) {
    if (&left == &right) {
        /* self-assignment */
    }
    left.i -= right.i;
    return left;
}

Integer &operator*=(Integer &left, const Integer &right) {
    if (&left == &right) {
        /* self-assignment */
    }
    left.i *= right.i;
    return left;
}

Integer &operator/=(Integer &left, const Integer &right) {
    require(right.i != 0, "divide by zero");
    if (&left == &right) {
        /* self-assignment */
    }
    left.i /= right.i;
    return left;
}

Integer &operator%=(Integer &left, const Integer &right) {
    require(right.i != 0, "modulo by zero");
    if (&left == &right) {
        /* self-assignment */
    }
    left.i %= right.i;
    return left;
}

Integer &operator^=(Integer &left, const Integer &right) {
    if (&left == &right) {
        /* self-assignment */
    }
    left.i ^= right.i;
    return left;
}

Integer &operator&=(Integer &left, const Integer &right) {
    if (&left == &right) {
        /* self-assignment */
    }
    left.i &= right.i;
    return left;
}

Integer &operator|=(Integer &left, const Integer &right) {
    if (&left == &right) {
        /* self-assignment */
    }
    left.i |= right.i;
    return left;
}

Integer &operator>>=(Integer &left, const Integer &right) {
    if (&left == &right) {
        /* self-assignment */
    }
    left.i >>= right.i;
    return left;
}

Integer &operator<<=(Integer &left, const Integer &right) {
    if (&left == &right) {
        /* self-assignment */
    }
    left.i <<= right.i;
    return left;
}

// Conditional operators return true/false:
int operator==(const Integer &left, const Integer &right) {
    return left.i == right.i;
}

int operator!=(const Integer &left, const Integer &right) {
    return left.i != right.i;
}

int operator<(const Integer &left, const Integer &right) {
    return left.i < right.i;
}

int operator>(const Integer &left, const Integer &right) {
    return left.i > right.i;
}

int operator <=(const Integer &left, const Integer &right) {
    return left.i <= right.i;
}

int operator >=(const Integer &left, const Integer &right) {
    return left.i >= right.i;
}

int operator&&(const Integer &left, const Integer &right) {
    return left.i && right.i;
}

int operator||(const Integer &left, const Integer &right) {
    return left.i || right.i;
}

void h(Integer &c1, Integer &c2) {
    // A complex expression:
    c1 += c1 * c2 + c2 % c1;
#define TRY(op) \
    out << "c1 = "; c1.print(out); \
    out << ", c2 = "; c2.print(out); \
    out << "; c1 " #op " c2 produces "; \
    (c1 op c2).print(out); \
    out << endl;
    TRY(+)
    TRY(-)
    TRY(*)
    TRY(/)
    TRY(%)

    TRY(^)
    TRY(&)
    TRY(|)
    TRY(<<)
    TRY(>>)

    TRY(+=)
    TRY(-=)
    TRY(*=)
    TRY(/=)
    TRY(%=)

    TRY(^=)
    TRY(&=)
    TRY(|=)
    TRY(>>=)
    TRY(<<=)

    // Conditionals:
#define TRYC(op) \
    out << "c1 = "; c1.print(out); \
    out << ", c2 = "; c2.print(out); \
    out << "; c1 " #op " c2 produces "; \
    out << (c1 op c2); \
    out << endl;
    TRYC(<)
    TRYC(>)
    TRYC(==)
    TRYC(!=)
    TRYC(<=)
    TRYC(>=)
    TRYC(&&)
    TRYC(||)
}

// Member operators (implicit "this"):
class Byte { // Combine this with UNARY.CPP
public:
    Byte(unsigned char B = 0) : b(B) {
        // Empty body
    }

    // No side effects:const member function:
    const Byte operator+(const Byte &right) const {
        return Byte(b + right.b);
    }
    const Byte operator-(const Byte &right) const {
        return Byte(b - right.b);
    }
    const Byte operator*(const Byte &right) const {
        return Byte(b * right.b);
    }
    const Byte operator/(const Byte &right) const {
        require(right.b != 0, "divide by zero");
        return Byte(b / right.b);
    }
    const Byte operator%(const Byte &right) const {
        require(right.b != 0, "modulo by zero");
        return Byte(b % right.b);
    }
    const Byte operator^(const Byte &right) const {
        return Byte(b ^ right.b);
    }
    const Byte operator&(const Byte &right) const {
        return Byte(b & right.b);
    }
    const Byte operator|(const Byte &right) const {
        return Byte(b | right.b);
    }
    const Byte operator<<(const Byte &right) const {
        return Byte(b << right.b);
    }
    const Byte operator>>(const Byte &right) const {
        return Byte(b >> right.b);
    }

    // Assignments modify & return lvalue.
    // operator= can only be a member function:
    Byte &operator=(const Byte &right) {
        // Handle self-assignment:
        if (this == &right) {
            return *this;
        }
        b = right.b;
        return *this;
    }
    Byte &operator+=(const Byte &right) {
        if (this == &right) {
            /* self-assignment */
        }
        b += right.b;
        return *this;
    }
    Byte &operator-=(const Byte &right) {
        if (this == &right) {
            /* self-assignment */
        }
        b -= right.b;
        return *this;
    }
    Byte &operator*=(const Byte &right) {
        if (this == &right) {
            /* self-assignment */
        }
        b *= right.b;
        return *this;
    }
    Byte &operator/=(const Byte &right) {
        require(right.b != 0, "divide by zero");
        if (this == &right) {
            /* self-assignment */
        }
        b /= right.b;
        return *this;
    }
    Byte &operator%=(const Byte &right) {
        require(right.b != 0, "modulo by zero");
        if (this == &right) {
            /* self-assignment */
        }
        b %= right.b;
        return *this;
    }
    Byte &operator^=(const Byte &right) {
        if (this == &right) {
            /* self-assignment */
        }
        b ^= right.b;
        return *this;
    }
    Byte &operator&=(const Byte &right) {
        if (this == &right) {
            /* self-assignment */
        }
        b &= right.b;
        return *this;
    }
    Byte &operator|=(const Byte &right) {
        if (this == &right) {
            /* self-assignment */
        }
        b |= right.b;
        return *this;
    }
    Byte &operator>>=(const Byte &right) {
        if (this == &right) {
            /* self-assignment */
        }
        b >>= right.b;
        return *this;
    }
    Byte &operator<<=(const Byte &right) {
        if (this == &right) {
            /* self-assignment */
        }
        b <<= right.b;
        return *this;
    }

    // Conditional operators return true/false
    int operator==(const Byte &right) const {
        return b == right.b;
    }
    int operator!=(const Byte &right) const {
        return b != right.b;
    }
    int operator>(const Byte &right) const {
        return b > right.b;
    }
    int operator<(const Byte &right) const {
        return b < right.b;
    }
    int operator>=(const Byte &right) const {
        return b >= right.b;
    }
    int operator<=(const Byte &right) const {
        return b <= right.b;
    }
    int operator&&(const Byte &right) const {
        return b && right.b;
    }
    int operator||(const Byte &right) const {
        return b || right.b;
    }

    // Write the contents to an ostream:
    void print(ostream &os) const {
        os << "0x" << hex << int(b) << dec;
    }
private:
    unsigned char b;
};

void k(Byte &b1, Byte &b2) {
    b1 = b1 * b2 + b2 % b1;

#define TRY2(op) \
    out << "b1 = "; b1.print(out); \
    out << ", b2 = "; b2.print(out); \
    out << "; b1 " #op " b2 produces "; \
    (b1 op b2).print(out); \
    out << endl;

    b1 = 9;
    b2 = 47;

    TRY2(+)
    TRY2(-)
    TRY2(*)
    TRY2(/)
    TRY2(%)

    TRY2(^)
    TRY2(&)
    TRY2(|)
    TRY2(<<)
    TRY2(>>)

    TRY2(+=)
    TRY2(-=)
    TRY2(*=)
    TRY2(/=)
    TRY2(%=)

    TRY2(^=)
    TRY2(&=)
    TRY2(|=)
    TRY2(>>=)
    TRY2(<<=)
    TRY2(=) //! Assignment operator; 仅能用于成员函数

    // Conditionals:
#define TRYC2(op) \
    out << "b1 = "; b1.print(out); \
    out << ", b2 = "; b2.print(out); \
    out << "; b1 " #op " b2 produces "; \
    out << (b1 op b2); \
    out << endl;

    b1 = 9;
    b2 = 47;

    TRYC2(<)
    TRYC2(>)
    TRYC2(==)
    TRYC2(!=)
    TRYC2(<=)
    TRYC2(>=)
    TRYC2(&&)
    TRYC2(||)

    // Chained assignment:
    Byte b3 = 92;
    b1 = b2 = b3;
}

int main() {
    Integer c1(47);
    Integer c2(9);
    h(c1, c2);

    out << "\n member functions:" << endl;
    Byte b1(47);
    Byte b2(9);
    k(b1, b2);

    return 0;
} ///:~
