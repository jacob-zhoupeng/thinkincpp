//: C09:Seeking.cpp
// Seeking in iostreams

#include <iostream>
#include <fstream>

#include "../require.h"

using namespace std;

int main(int argc, char* argv[]) {
    requireArgs(argc, 2);

    ifstream in(argv[1]);
    assure(in, argv[1]); // File must already exist

    in.seekg(0, ios::end); // End of file
    streampos sp = in.tellg(); // Size of file
    cout << "file size = " << sp << endl;

    in.seekg(-sp/10, ios::end);
    streampos sp2 = in.tellg();
    in.seekg(0, ios::beg); // Start of file
    cout << in.rdbuf(); // Print whole file

    in.seekg(sp2);  // Move to streampos
    // Prints the last 1/10th of the file:
    cout << endl << endl << in.rdbuf() << endl;

    return 0;
} ///:~
