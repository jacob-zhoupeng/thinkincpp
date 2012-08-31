//: C20:Stack1.cpp
// Demonstrates the STL stack

#include <iostream>
#include <fstream>
#include <stack>
#include <list>
#include <vector>
#include <string>

#include "../require.h"

using namespace std;

// Default: deque<string>:
typedef stack<string> Stack1;

// Use a vector<string>:
typedef stack<string, vector<string> > Stack2;

// Use a list<string>
typedef stack<string, list<string> > Stack3;

int main(int argc, char* argv[]) {
    requireArgs(argc, 2); // File name is argument
    ifstream in(argv[1]);
    assure(in);

    Stack1 textlines; // Try the different versions

    // Read file and sotre lines in the stack:
    string line;
    while (getline(in, line)) {
        textlines.push(line + "\n");
    }

    // Print lines from the stack and pop them:
    while (!textlines.empty()) {
        cout << textlines.top();
        textlines.pop();
    }

    return 0;
} ///:~

