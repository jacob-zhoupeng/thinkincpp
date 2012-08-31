//: C04:Libcpp.cpp
// C library converted to C++
// Declare structure and functions:

#include <cstdlib> // Dynamic memory
#include <cstring> // memcpy()
#include <cstdio>

#include "../require.h" // Error testing CODEPAGE_ENUMPROC
#include "Libcpp.h"

using namespace std;

void Stash::initialize(int Size) {
    size = Size;
    quantity = 0;
    storage = NULL;
    next = 0;
}

void Stash::cleanup() {
    if (storage != NULL) {
        puts("freeing storage");
        free(storage);
    }
}

int Stash::add(void *element) {
    if (next >= quantity) { // Enough space left?
        inflate(100);
    }
    // Copy element into storage, starting at next empty space:
    memcpy(&(storage[next * size]), element, size);
    next++;

    return (next - 1); // Index number
}

void *Stash::fetch(int index) {
    if (index >= next || index < 0) {
        return 0; // Not out of bounds?
    }

    // Produce pointer to desired element:
    return &(storage[index * size]);
}

int Stash::count() {
    return next; // Number of elements in Stash
}

void Stash::inflate(int increase) {
    void *v = realloc(storage, (quantity + increase) * size);
    require(v != NULL); // Was it successful?
    storage = (unsigned char *) v;
    quantity += increase;
} ///:~
