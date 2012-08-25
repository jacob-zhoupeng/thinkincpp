//: C11:Pasconst.cpp
// Passing references as const

void f(int &) {
    // Empty body
}

void g(const int &) {
    // Empty body
}

int main() {
    //! f(1); // Error
    g(1);
} ///:~
