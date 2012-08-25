//: C11:Passtruc.cpp
// Passing a big structure

struct big {
    char buf[100];
    int i;
    long d;
} B, B2;

big bigfun(big b) {
    b.i = 100; // Do something to the argument

    return b;
}

int main() {
    B2 = bigfun(B);

    return 0;
} ///:~
