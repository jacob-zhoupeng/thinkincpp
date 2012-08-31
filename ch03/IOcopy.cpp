//: C03:IOcopy.cpp
// fstreams for opening files.
// Copies itself to TMP.TXT

#include <fstream>

#include "../require.h"

using namespace std;

int main() {
    ifstream infile(__FILE__);
    assure(infile, __FILE__);

    ofstream outfile("tmp.txt");
    assure(outfile, "tmp.txt");

    char ch;

    while (infile.get(ch) != '\0') {
        outfile.put(ch);
    }

    return 0;
} ///:~
