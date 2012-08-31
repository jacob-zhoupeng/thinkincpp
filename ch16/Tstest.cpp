//: C16:Tstest.cpp
// Test TStash
#include <fstream>
#include <vector>
#include <string>

#include "../require.h"
#include "TStash.h"

using namespace std;

ofstream out("tstest.out");

class Int {
public:
    Int(int I = 0) : i(I) {
        out << ">" << i << endl;
    }
    ~Int() {
        out << "~" << i << endl;
    }
    operator int() const  {
        return i;
    }
    friend ostream &operator<<(ostream &os, const Int &x) {
        return os << x.i;
    }
private:
    int i;
};

int main() {
    TStash<Int> intStash; // Instantiate for int

    for (int i = 0; i < 30; i++) {
        intStash.add(new Int(i));
    }

    TStashIter<Int> Intit(intStash);
    Intit.forward(5);
    for (int j = 0; j < 20; j++, Intit++) {
        Intit.remove(); // Default removal
    }
    for (int k = 0; k < intStash.count(); k++) {
        if (intStash[k]) {
            // Remove() causes "holes"
            out << *intStash[k] << endl;
        }
    }

    ifstream file(__FILE__);
    assure(file, __FILE__);
    // Instantiate for String:
    TStash<string> stringStash;
    string line;

    while (getline(file, line)) {
        stringStash.add(new string(line));
    }

    for (int u = 0; u < stringStash.count(); u++) {
        if (stringStash[u]) {
            out << *stringStash[u] << endl;
        }
    }

    TStashIter<string> it(stringStash);
    int j = 25;
    it.forward(j);

    while (it) {
        out << j++ << ": " << it->c_str() << endl;
        it++;
    }

    return 0;
} ///:~
