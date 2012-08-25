//: C03:Debug2.cpp
// Framework for writing debug CODEPAGE_ENUMPROC

#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

#define DEBUG

int main(int argc, char *argv[]) {
    int debug = 0;

    if (argc > 1) { // If more than one argument
        if (*argv[1] == 'd') {
            debug++; // Set the debug flag
        } else {
            cout << "usage: debug2 OR debug2 d" << endl <<
                 "optional flag turns debugger on.";
            exit(1); // Quit program
        }
    }
    // ....
#ifdef DEBUG
    if (debug) {
        cout << "debugger on" << endl;
    }
#endif // DEBUG
    // ...

    return 0;
} ///:~
