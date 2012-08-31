//: C14:FName1.cpp
// An fstream with a file name

#include <iostream>
#include <fstream>
#include <strstream>

#include "../require.h"

using namespace std;

class FName1 {
public:
    FName1() : Name(buf, bsize), nameset(0) {
        // Empty body
    }
    FName1(const char *filename) : File(filename), Name(buf, bsize) {
        assure(File, filename);
        Name << filename << ends;
        nameset = 1;
    }
    const char *name() const {
        return buf;
    }
    void name(const char *newname) {
        if (nameset) {
            return; // Don't overwrite
        }
        Name << newname << endl;
        nameset = 1;
    }
    operator ifstream &() {
        return File;
    }
private:
    ifstream File;
    enum {
        bsize = 100
    };
    char buf[bsize];
    ostrstream Name;
    int nameset;
};

int main() {
    FName1 file(__FILE__);
    cout << file.name() << endl;

    // Error: rdbuf not a member:
    //! 自动类型转换仅发生在函数调用时，成员
    //! 选择时不会发生自动类型转换
    //! cout << file.rdbuf() << endl;

    return 0;
} ///:~
