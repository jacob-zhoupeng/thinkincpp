//: C20:WordList.cpp
// Display a list of words used in a document

#include <string>
#include <cstring>
#include <set>
#include <iostream>
#include <fstream>
#include <iterator>

#include "../require.h"

using namespace std;

const char* delimiters = " \t;()\"<>:{}[]+-=&*#.,/\\~";

int main(int argc, char* argv[]) {
    //requireArgs(argc, 2);

    //std::ifstream in(argv[1]);
    std::ifstream in(__FILE__);
    assure(in, argv[1]);

    std::set<std::string> wordlist;
    std::string line;

    while (getline(in, line)) {
        // Capture individual words:
        char* s = strtok((char*)line.c_str(), delimiters); // Cast probably
                                                           // won't crash

        while (s) {
            wordlist.insert(s); // Auto type conv.
            s = strtok(0, delimiters);
        }
    }

    // Output results: 输出有序,set默认是排好序的
    std::copy(wordlist.begin(), wordlist.end(),
            ostream_iterator<string>(cout, "\n"));

    return 0;
} ///:~

/**
 * strtok(): string.h
 *
 * strtok() takes the starting address of a character buffer (the  first 
 * argument) and looks for delimiters (the second argument). It replaces 
 * the delimiter with a zero, and returns the address of the beginning of 
 * the token. If you call it subsequent times with a first argument of 
 * zero it will continue extracting tokens from the rest of the string 
 * until it finds the end. 
 */

