//: C20: Stack2.cpp
// Converting a list to a stack

#include <iostream>
#include <fstream>
#include <list>
#include <stack>
#include <string>

#include "../require.h"

using namespace std;

// Expects a stack:
template<class stk>
void stackOut(stk& s, ostream& os = cout) {
    while (!s.empty()) {
        os << s.top() << "\n";
        s.pop();
    }
}

class Line {
public:
    Line(string s) : line(s) {
        lspaces = line.find_first_not_of(' ');
        if (lspaces == string::npos) {
            lspaces = 0;
        }
        line = line.substr(lspaces);
    }

    friend ostream& operator<<(ostream& os, const Line& l) {
        for (int i = 0; i < l.lspaces; i++) {
            os << ' ';
        }
        return os << l.line;
    }

    // Other functios here...
private:
    string line; // Without leading spaces
    int lspaces; // Number of leading spaces
};

int main(int argc, char* argv[]) {
    requireArgs(argc, 2); // File name is argument
    ifstream in(argv[1]);
    assure(in);

    list<Line> lines;

    // Read file and store lines in the list:
    string s;
    while (getline(in, s)) {
        lines.push_front(s);
    }

    // Turn the list into a stack for printing:
    stack<Line, list<Line> > stk(lines);
    stackOut(stk);

    return 0;
} ///:~

