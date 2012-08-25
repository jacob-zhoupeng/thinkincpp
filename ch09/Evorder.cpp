//: C09:Evorder.cpp
// Inline evaluation order

class Forward {
public:
    Forward() : i(0) {
        // Empty body
    }
    // Call to undeclared function:
    int f() const {
        return g() + 1;
    }
    int g() const {
        return i;
    }
private:
    int i;
};

int main() {
    Forward F;

    F.f();

    return 0;
} ///:~
