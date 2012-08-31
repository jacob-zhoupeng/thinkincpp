//: C19:Stype.cpp
// Type a file to standard output

#include <fstream>
#include <iostream>

#include "../require.h"

using namespace std;

int main(int argc, char *argv[]) {
    requireArgs(argc, 2); // Must have a command line
    ifstream in(argv[1]);
    assure(in, argv[1]); // Ensure file exists
    cout << in.rdbuf(); // Outputs entire file

    return 0;
} ///:~
