//: C16:Tstktst.cpp
// Use template list & iterator
#include <iostream>
#include <fstream>
#include <string>

#include "../require.h"
#include "TStack.h"

using namespace std;

int main() {
    ifstream file(__FILE__);
    assure(file, __FILE__);
    TStack<string> textlines;

    // Read file and store lines in the list:
    string line;
    while(getline(file, line) != NULL) {
        textlines.push(new string(line));
    }

    int i = 0;
    // Use iterator to print lines from the list:
    TStackIterator<string> it(textlines);
    TStackIterator<string> *it2 = NULL;
    while (it != NULL) {
        cout << *it.current() << endl;
        it++;
        if (++i == 10) {
            // Remember 10th line
            it2 = new TStackIterator<string>(it);
        }
    }
    cout << *(it2->current()) << endl;
    delete it2;

    return 0;
} ///:~
