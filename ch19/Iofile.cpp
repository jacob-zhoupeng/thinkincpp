//: C19:Iofile.cpp
// Reading & writing one file

#include <iostream>
#include <fstream>

#include "../require.h"

using namespace std;

int main() {
    ifstream in("iofile.cpp");
    assure(in, "iofile.cpp");
    ofstream out("iofile.out");
    assure(out, "iofile.out");

    out << in.rdbuf(); // Copy file
    in.close();
    out.close();

    // Open for reading and writing:
    ifstream in2("iofile.out", ios::in | ios::out);
    assure(in2, "iofile.out");
    ostream out2(in2.rdbuf());

    cout << in2.rdbuf(); // Print whole file
    out2 << "Where does this end up?";
    out2.seekp(0, ios::beg);
    out2 << "And what about this?";
    in2.seekg(0, ios::beg);
    cout << in2.rdbuf();

    return 0;
} ///:~
