//: C20:Strvector.cpp
// A vector of strings

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <iterator>
#include <sstream>

#include "../require.h"

using namespace std;

int main(int argc, char* argv[]) {
    requireArgs(argc, 2);

    ifstream in(argv[1]);
    assure(in, argv[1]);

    vector<string> strings;

    string line;
    while (getline(in, line)) {
        strings.push_back(line);
    }

    // Do Someting to the strings...
    int i = 1;
    vector<string>::iterator w;
    for (w = strings.begin(); w != strings.end(); w++) {
        ostringstream ss;
        ss << i++;
        *w = ss.str() + ": " + *w;
    }

    // Now send them out:
    copy(strings.begin(), strings.end(), ostream_iterator<string>(cout, "\n"));

    // Since they aren't pointers, string
    // objects clean themselves up!

    return 0;
} ///:~

