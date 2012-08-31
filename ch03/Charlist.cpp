//: C03:Charlist.cpp
// Display all the ASCII characters.
// Demonstrates "for."
#include <iostream>

using namespace std;

int main() {
    for (int i = 0; i < 128; i = i+1) {
        if (i != 26) { // ANSI Terminal/ANSI.SYS Clear screen
            cout << " value: " << i << " character: "
                << char(i) << endl; // Type conversion
        }
    }

    return 0;
} ///:~
