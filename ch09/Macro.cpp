//: C09:Macro.cpp
// Side effectc with macros

#include <fstream>

#include "../require.h"

using namespace std;

#define band(x) (((x) > 5 && (x) < 10) ? (x) : 0)

int main() {
    ofstream out("macro.out");
    assure(out, "macro.out");

    for (int i = 4; i < 11; i++) {
        int a = i;
        out << "a = " << a << endl << '\t';
        out << "band(++a) = " << band(++a) << endl;
        out << "\t a = " << a << endl;
    }

    return 0;
} ///:~
