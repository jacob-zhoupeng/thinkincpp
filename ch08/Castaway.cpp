//: C08:Castaway.cpp
// "Casting away" constness

class Y {
public:
    Y() {
        i = j = 0;
    }
    void f() const;
private:
    int i;
    int j;
};

void Y::f() const {
    //! i++; // Error -- const member function
    ((Y *) this)->j++; // OK: cast away const-ness
}

int main() {
    const Y yy;

    yy.f(); // Actually changes it!

    return 0;
} ///:~
