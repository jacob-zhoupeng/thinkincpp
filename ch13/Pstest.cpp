//: C13:Pstest.cpp
// {L} PStash
// Test of pointer stash

#include <iostream>
#include <fstream>

#include "../require.h"
#include "PStash.h"
#include "Strings.h"

using namespace std;

int main() {
    PStash intStash;

    // new works with built-in types, too:
    for (int i = 0; i < 25; i++) {
        intStash.add(new int(i)); // Pseudo-constructor.
    }
    for (int u = 0; u < intStash.count(); u++) {
        cout << "intStash[" << u << "] = "
            << *(int *)intStash[u] << endl;
    }

    ifstream infile(__FILE__);
    assure(infile, __FILE__);
    const int bufsize = 80;
    char buf[bufsize];
    PStash stringStash;

    // Use global function makeString:
    for (int j = 0; j < 10; j++) {
        if (infile.getline(buf, bufsize) != NULL) {
            stringStash.add(makeString(buf));
        }
    }
    // Use static member make:
    while (infile.getline(buf, bufsize) != NULL) {
        stringStash.add(String::make(buf));
    }

    // Print out the strings:
    for (int v = 0; stringStash[v] != NULL; v++) {
        //! 调用了String类的operator char *()函数
        char *p = *(String *)stringStash[v];
        cout << "stringStash[" << v << "] = "
            << p << endl;
    }

    return 0;
} ///:~
