//: C19:FileClass.cpp {0}
// Implementation

#include <cstdlib>

#include "FileClass.h"

using namespace std;

FileClass::FileClass(const char* fname, const char* mode) {
    f = fopen(fname, mode);
    if (f == NULL) {
        printf("%s: file not found\n", fname);
        exit(1);
    }
}

FileClass::~FileClass() {
    fclose(f);
}

FILE* FileClass::fp() {
    return f;
}
