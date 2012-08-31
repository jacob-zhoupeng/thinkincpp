//: C19:FileClass.h
// Stdio files wrapped
#ifndef FILECLASS_H_INCLUDED
#define FILECLASS_H_INCLUDED

#include <cstdio>

class FileClass {
public:
    FileClass(const char* fname, const char* mode="r");
    ~FileClass();
    std::FILE* fp();
private:
    std::FILE *f;
};

#endif // FILECLASS_H_INCLUDED
