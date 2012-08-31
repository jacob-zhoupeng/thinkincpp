//: C18:ReplaceAndGrow.cpp
#include <string>
#include <iostream>

using namespace std;

int main() {
    string bigNews("I saw Elvis in a UFO. "
                   "I have been working too hard.");
    string replacement("wig");

    // The first arg says "replace chars
    // beyond the end of the existing string":
    bigNews.replace(bigNews.size(), replacement.size(), replacement);

    cout << bigNews << endl;

    return 0;
} ///:~
