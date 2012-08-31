//: C14:Inhstak.cpp
// {L} ../C14/Stack11
// Specilializing the Stack class

#include <iostream>
#include <fstream>
#include <string>

#include "../require.h"
#include "Stack11.h"

using namespace std;

class StringList : public Stack {
public:
    void push(string *str) {
        Stack::push(str);
    }
    string *peek() const {
        return (string *)Stack::peek();
    }
    string *pop() {
        return (string *)Stack::pop();
    }
};

int main() {
    ifstream file(__FILE__);
    assure(file, __FILE__);

    string line;
    StringList textlines;
    while (getline(file, line)) {
        textlines.push(new string(line));
    }

    string *s;
    while ((s = textlines.pop()) != NULL) { // No cast!
        cout << *s << endl;
    }

    return 0;
} ///:~
