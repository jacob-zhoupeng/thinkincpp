//: C03:Forward.cpp
// Forward function & data declarations

#include <iostream>

using namespace std;

// This is not actually external, but the
// compiler must be told it exists somewhere:
extern int i;
extern void foo();

int main() {
    i = 0;
    foo();

    return 0;
}

int i; // The data definition

void foo() {
    i++;
    cout << i;
} ///:~
