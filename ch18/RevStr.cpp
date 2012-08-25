//: C18:RevStr.cpp
// Print a string in reverse

#include <string>
#include <iostream>

using namespace std;

int main() {
    string s("987654321");

    // Use this iterator to walk backwards:
    string::reverse_iterator rev;

    // "Incrementing" the reverse iterator moves
    // it to successively lower string elements:
    for (rev = s.rbegin(); rev != s.rend(); rev++) {
        cout << *rev << " ";
    }

    return 0;
} ///:~
