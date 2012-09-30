//: C26:Memcheck.h
// Memory testing system
// This file is only included if you want to
// use the special palcement syntax to find
// out the line number where "new" was called.
#ifndef MEMCHECK_H
#define MEMCHECK_H

#include <cstdlib> // size_t

// Use placement syntax to pass extra arguments.
// From an idea by Reg Charney:
void* operator new(std::size_t sz, char* file, int line);
#define new new(__FILE__, __LINE__)

#endif // MEMCHECK_H ///:~