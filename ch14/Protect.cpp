//: C14:Protect.cpp {0}
// The protected keyword

#include <fstream>

using namespace std;

class Base {
public:
    Base(int I = 0) : i(I) {
        // Empty body
    }
    int value(int m) const {
        return m * i;
    }
protected:
    int read() const {
        return  i;
    }
    void set(int I) {
        i = I;
    }
private:
    int i;
};

class Derived : public Base {
public:
    Derived(int J = 0) : j (J) {
        // Empty body
    }
    void change(int X) {
        set(X);
    }
private:
    int j;
};
