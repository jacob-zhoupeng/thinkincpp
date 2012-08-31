//: C09:Errtest.cpp
// Testing require.h

#include <fstream>

#include "../require.h"

using namespace std;

int main(int argc, char *argv[]) {
    int i = 1;

    require(i, "value must be nonzero");
    requireArgs(argc, 2);
    requireMinArgs(argc, 2);
    ifstream in(argv[1]);
    assure(in, argv[1]); // Use the file name
    ifstream nofile("nofile.xxx");
    assure(nofile); // The default argument
    ofstream out("tmp.txt");
    assure(out);

    return 0;
} ///:~
