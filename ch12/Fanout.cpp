//: C12:Fanout.cpp
// Type conversion fanout

class A {};
class B {};

class C {
public:
    operator A() const;
    operator B() const;
};

// Overloaded h();
void h(A);
void h(B);

int main() {
    C c;
    //! h(c); // Error: C -> A or C -> B ???

    return 0;
} ///:~

