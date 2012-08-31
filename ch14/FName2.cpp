//: C14:FName2.cpp
// Subtyping solves the problem

#include <iostream>
#include <fstream>
#include <strstream>

#include "../require.h"

using namespace std;

class FName2 : public ifstream {
public:
    FName2() : fname(buf, bsize), nameset(0) {
        // Empty body
    }
    FName2(const char *filename) : ifstream(filename), fname(buf, bsize) {
        assure(*this, filename);
        fname << filename << ends;
        nameset = 1;
    }
    const char *name() const {
        return buf;
    }
    void name(const char *newname) {
        if (nameset) {
            return; // Don't overwrite
        }
        fname << newname << ends;
        nameset = 1;
    }
private:
    enum {
        bsize = 100
    };
    char buf[bsize];
    ostrstream fname;
    int nameset;
};

int main() {
    FName2 file(__FILE__);

    assure(file, __FILE__);
    cout << "name: " << file.name() << endl;

    const int bsize = 100;
    char buf[bsize];

    file.getline(buf, bsize); // This works too!
    file.seekg(-200, ios::end);
    cout << file.rdbuf() << endl;

    return 0;
} ///:~
