//: C18:Replace.cpp
#include <string>
#include <iostream>

using namespace std;

void replaceChars(string &modifyMe, string findMe, string newChars) {
    // Look in modifyMe for the "find string"
    // starting at position 0
    unsigned int i = modifyMe.find(findMe, 0);
    // Did we find the string to replace?
    if (i != string::npos) {
        // Replace the find string with newChars
        modifyMe.replace(i, newChars.size(), newChars);
    }
}

int main() {
    string bigNews = "I though I saw Elvis in a UFO. "
                     "I have been working too hard.";
    string replacement("wig");
    string findMe("UFO");

    // Find "UFO" in bigNews and overwrite it:
    replaceChars(bigNews, findMe, replacement);

    cout << bigNews << endl;

    return 0;
} ///:~

