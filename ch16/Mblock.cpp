//: C16:Mblock.cpp
// Built-in types in templates
#include <iostream>

#include "../require.h"

using namespace std;

template<class T, int size = 100>
class Mblock {
public:
    T &operator[](int index) {
        require(index >= 0 && index < size);
        return array[index];
    }
private:
    T array[size];
};

class Number {
public:
    Number(float F = 0.0f) : f(F) {}
    Number &operator=(const Number &n) {
        f = n.f;
        return *this;
    }
    operator float() const {
        return f;
    }
    friend ostream &operator<<(ostream &os, const Number &x) {
        return os << x.f;
    }
private:
    float f;
};

template<class T, int sz = 20>
class Holder {
public:
    Holder() : np(NULL) {
        // ясЁы╪сть
    }
    T &operator[](int i) {
        require(i >= 0 && i < sz);
        if (np == NULL) {
            np = new Mblock<T, sz>;
        }
        return np->operator[](i);
    }
private:
    Mblock<T, sz> *np;
};

int main() {
    Holder<Number, 20> H;

    for (int i = 0; i < 20; i++) {
        H[i] = i;
    }

    for (int j = 0; j < 20; j++) {
        cout << H[j] << endl;
    }

    return 0;
} ///:~
