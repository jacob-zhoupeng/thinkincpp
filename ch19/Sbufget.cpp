//: C19:Sbufget.cpp
// Get directly into a streambuf

#include <fstream>
#include <iostream>

#include "../require.h"

using namespace std;

int main() {
    ifstream in("Sbufget.cpp");
    assure(in, "sbufget.cpp");

    while (in.get(*cout.rdbuf())) {
        in.ignore();
    }

    return 0;
} ///:~
