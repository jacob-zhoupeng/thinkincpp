//: C19:Makemain.cpp
// From Thinking in C++, 2nd Edition
// (c) Bruce Eckel 1998
// Copyright notice in Copyright.txt
// Create a shell main() file

#include <fstream>
#include <strstream>
#include <cstring>
#include <cctype>

#include "../require.h"

using namespace std;

int main(int argc, char* argv[]) {
    requireArgs(argc, 2);

    ofstream mainfile(argv[1]);
    assure(mainfile, argv[1]);

    istrstream name(argv[1]);
    ostrstream CAPname;

    char c;
    while (name.get(c)) {
        CAPname << char(toupper(c));
    }
    CAPname << ends;
    mainfile << "//" << ": " << CAPname.rdbuf()
        << " -- " << endl
        << "#include <iostream>" << endl
        << "main() {" << endl << endl
        << "}" << endl;

    return 0;
} ///:~

