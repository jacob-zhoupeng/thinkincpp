//: C05:Private.cpp
// Setting the boundary

struct B {
public:
    int i;
    void foo();
private:
    char j;
    float f;
};

void B::foo() {
    i = 0;
    j = '0';
    f = 0.0;
}; //! semicolon is optional

int main() {
    B b;

    b.i = 1; // OK, public
    //! b.j = '1'; // Illegal, private
    //! b.f = 1.0; // Illegal, private

    return 0;
} ///:~
