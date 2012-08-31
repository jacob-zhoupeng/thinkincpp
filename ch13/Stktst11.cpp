//: C13:Stktst11.cpp
// {L} Stack11
// Test new Stack

#include <iostream>
#include <fstream>

#include "../require.h"
#include "Stack11.h"
#include "Strings.h"

using namespace std;

int main() {
    // Could also use command-line argument:
    ifstream file(__FILE__);
    assure(file, __FILE__);
    const int bufsize = 100;
    char buf[bufsize];
    Stack textlines;

    // Read file and store lines in the Stack:
    while (file.getline(buf, bufsize) != NULL) {
        textlines.push(String::make(buf));
    }

    // Pop lines from the Stack and print them:
    String *s;
    while ((s = (String *) textlines.pop()) != NULL) {
        cout << *s << endl; //! 调用String类函数operator char *()
    }

    return 0;
} ///:~
