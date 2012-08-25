//: C20:Reversible.cpp
// Using reversible containers

#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream in("Reversible.cpp");
    string line;
    vector<string> lines;

    while (getline(in, line)) {
        lines.push_back(line);;
    }

    vector<string>::reverse_iterator r;
    for (r = lines.rbegin(); r != lines.rend(); r++) {
        cout << *r << endl;
    }

    return 0;
} ///:~

