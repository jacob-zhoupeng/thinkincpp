//: C18:CmpIter.cpp
// Find a group of characters in a string
#include <string>
#include <iostream>

using namespace std;

// Case insensitive compare function:
int stringCmpi(const string& s1, const string& s2) {
    // Select the first element of each string:
    string::const_iterator p1 = s1.begin();
    string::const_iterator p2 = s2.begin();

    // Don't run past the end:
    while (p1 != s1.end() && p2 != s2.end()) {
        if (toupper(*p1) != toupper(*p2)) {
            // Report which was lexically greater:
            return (toupper(*p1) < toupper(*p2)) ? -1 : 1;
        }
        p1++;
        p2++;
    }

    // If they match up to the detected eos, say
    // which was longer. Return 0 if the same.
    return (s2.size() - s1.size());
}

int main() {
    string s1("Mozart");
    string s2("Modigliani");

    cout << stringCmpi(s1, s2) << endl;

    return 0;
} ///:~
