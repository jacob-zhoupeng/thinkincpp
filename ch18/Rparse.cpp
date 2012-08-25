//: C18:Rparse.cpp
// Reverse the order of words in a string

#include <string>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    // The ';' characters will be delimiters
    string s("now.;sense;make;to;going;is;This");
    cout << s << endl;

    // To store the words:
    vector<string> strings;

    // The last element of the string:
    int last = s.size();

    // The beginning of the the current word:
    unsigned int current = s.rfind(';');

    // Walk backward through the string:
    while (current != string::npos) {
        // Push each word into the vector.
        // Current is incremented before copying to
        // avoid copying the delimiter.
        current++;
        strings.push_back(s.substr(current, last-current+1));

        // Back over the delimiter we just found,
        // and set last to the end of the next word
        current -= 2;
        last = current;

        // Find the next delimiter
        current = s.rfind(';', current);
    }

    // Pick up the first word - it's not
    // preceded by a delimiter
    strings.push_back(s.substr(0, last-current));

    // Print them in the new order:
    for (unsigned int j = 0; j < strings.size(); j++) {
        cout << strings[j] << " ";
    }

    return 0;
} ///:~
