//: C08:Mutable.cpp
// The "mutable" keyword

class Y {
public:
    Y() {
        i = j = 0;
    }
    void f() const;
private:
    int i;
    mutable int j;
};

void Y::f() const {
    //! i++; // Error -- const member function
    j++; // OK: mutable
}

int main() {
    const Y yy;

    yy.f(); // Actually changes it!

    return 0;
} ///:~
