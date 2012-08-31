//: C20:Stack3.cpp
// Using a vector as a stack; modified Stack1.cpp

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "../require.h"

using namespace std;

int main(int argc, char* argv[]) {
    requireArgs(argc, 2);
    ifstream in(argv[1]);
    assure(in);

    vector<string> textlines;
    string line;
    while (getline(in, line)) {
        textlines.push_back(line + "\n");
    }

    while (!textlines.empty()) {
        cout << textlines.back();
        textlines.pop_back();
    }

    return 0;
} ///:~

