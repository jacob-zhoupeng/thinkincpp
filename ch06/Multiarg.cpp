//: C06:Multiarg.cpp
// Multiple constructor arguments
// with aggregate initialization

class X {
public:
    X(int I, int J) {
        i = I;
        j = J;
    }
private:
    int i;
    int j;
};

int main() {
    X xx[] = {
        X(1, 2), X(3, 4),
        X(5, 6), X(7, 8)
    };

    return 0;
} ///:~
