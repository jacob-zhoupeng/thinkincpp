//: C11:Stopcc.cpp
// Preventing copy-constructor

class NoCC {
public:
    NoCC(int I = 0) : i(I) {
        // Empty body
    }
private:
    int i;
    NoCC(const NoCC &); // No definition
};

void f(NoCC);

int main() {
    NoCC n;

    //! f(n); // Error: copy-constructor called
    //! NoCC n2 = n; // Error: c-c called
    //! NoCC n3(n); // Error: c-c called

    return 0;
} ///:~

