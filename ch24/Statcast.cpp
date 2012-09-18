//: C24:Statcast.cpp
// Examples of static_cast

class Base { /* ... */ };

class Derived : public Base {
public:
    // ...
    // Automatic type conversion:
    operator int() {
        return 1;
    }
};

void func(int) {}

class Other {};

int main(int argc, char* argv[]) {
    int i = 0x7fff; // Max pos value = 32767
    long l;
    float f;

    // (1) typical castless conversions:
    l = i;
    f = i;

    // Also works:
    l = static_cast<long>(i);
    f = static_cast<float>(i);

    // (2) narrowing conversions:
    i = l; // May lose digits
    i = f; // May lose info

    // Says "I know," eliminates warnings:
    i = static_cast<int>(l);
    i = static_cast<int>(f);
    char c = static_cast<char>(i);

    // (3) forcing a conversion from void*:
    void* vp = &i;

    // Old way produces a dangerous conversion:
    float* fp = (float*)vp;

    // The new way is equally dangerous:
    fp = static_cast<float*>(vp);

    // (4) implicity type conversions, normally
    // performed by the compiler:
    Derived d;
    Base* bp = &d; // Upcast: normal and OK
    bp = static_cast<Base*>(&d); // More explicit

    int x = d; // Automatic type conversion
    x = static_cast<int>(d); // More explicity

    func(d); // Automatic type conversion
    func(static_cast<int>(d)); // More explicit

    // (5) Static Navigation of class hierarchies:
    Derived* dp = static_cast<Derived*>(bp);

    // ONLY an efficiency hack. dynamic_cast is
    // always safer. However:
    // Other* op = static_cast<Other*>(bp);
    // Conveniently gives an error message, while
    Other* op2 = (Other*)bp;
    // Does not.

    return 0;
} ///:~