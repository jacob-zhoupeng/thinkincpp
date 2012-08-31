//: C19:Strfile.cpp
// Stream I/O with files
// The difference between get() & getline()

#include <fstream>
#include <iostream>

#include "../require.h"

using namespace std;

#define SZ (100) // Buffer size

int main() {
    char buf[SZ];
    {
        ifstream in("strfile.cpp"); // Read
        assure(in, "strfile.cpp"); // Verify open
        ofstream out("strfile.out"); // Write
        assure(out, "strfile.out");
        int i = 1; // Line counter

        // A less-convenient approach for line input:
        while (in.get(buf, SZ)) { // Leaves \n in input
            in.get(); // Throw away next character (\n)
            cout << buf << endl; // Must add \n
            // File output just like standard I/O:
            out << i++ << ": " << buf << endl;
        }
    } // Destructors close in & out

    ifstream in("strfile.out");
    assure(in, "strfile.out");
    // More convenient line input:
    while (in.getline(buf, SZ)) { // Removes \n
        char* cp = buf;
        while (*cp != ':') {
            cp++;
        }
        cp += 2; // Past ": "
        cout << cp << endl; // Must still add \n
    }

    return 0;
} ///:~
