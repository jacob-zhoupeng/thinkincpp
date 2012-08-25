//: CXX:DelayedInstantiation.cpp
// Member functions of class templates are not
// instantiated until they're needed.

class X {
public:
    void f() {}
};

class Y {
public:
    void g() {}
};

template <typename T> 
class Z {
public:
    void a() { 
        t.f(); 
    }
    void b() {
        t.g();
    }
private:
    T t;
};

int main() {
    Z<X> zx;
    zx.a(); // Doesn't create Z<X>::b();

    Z<Y> zy;
    zy.b(); // Doesn't create Z<Y>::a();
    
    return 0;
} ///:~

