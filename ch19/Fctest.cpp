//: C19:Fctest.cpp
// {L} FileClass
// Testing class File

#include "../require.h"
#include "FileClass.h"

using namespace std;

int main(int argc, char *argv[]) {
    requireArgs(argc, 2);
    FileClass f(argv[1]); // Opens and tests
#define BSIZE (100)
    char buf[BSIZE];
    while (fgets(buf, BSIZE, f.fp())) {
        puts(buf);
    }

    return 0;
} // File automatically closed by destructor
///:~
