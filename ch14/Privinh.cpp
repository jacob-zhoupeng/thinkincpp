//: C14:Privinh.cpp
// Private inheritance

class Base1 {
public:
    char f() const {
        return 'a';
    }
    int g() const {
        return 2;
    }
    float h() const {
        return 3.0f;
    }
};

class Derived : Base1 { // Private inheritance
public:
    Base1::f; // Name publicizes member
    Base1::h;
};

int main() {
    Derived d;

    d.f();
    d.h();
    //! d.g(); // Error -- private function

    return 0;
} ///:~
