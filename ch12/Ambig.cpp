//: C12:Ambig.cpp
// Ambiguity in type conversion

class Y; // Class declaration

class X {
public:
    operator Y() const; // Convert X to Y
};

class Y {
public:
    Y(X); // Convert X to Y
};

void f(Y);

int main() {
    X x;
    //! f(x); // Error: ambiguous conversion

    return 0;
} ///:~
