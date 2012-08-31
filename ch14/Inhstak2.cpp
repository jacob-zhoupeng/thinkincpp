//: C14:Inhstak2.cpp
// {L} ../C14/Stack11
// Composition vs inheritance

#include <iostream>
#include <fstream>
#include <string>

#include "../require.h"
#include "Stack11.h"

using namespace std;

class StringList {
public:
    void push(string *str) {
        stack.push(str);
    }
    string *peek() const {
        return (string *)stack.peek();
    }
    string *pop() {
        return (string *)stack.pop();
    }
private:
    Stack stack; // Embed instead of inherit
};

int main() {
    ifstream file(__FILE__);
    assure(file, __FILE__);

    string line;
    StringList textlines;
    while (getline(file, line) != NULL) {
        textlines.push(new string(line));
    }

    string *s;
    while ((s = textlines.pop()) != NULL) { // No cast!
        cout << *s << endl;
    }

    return 0;
} ///:~
