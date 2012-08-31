//: C06:Stash3.cpp {0}
// Constructors & destructors

#include <cstdlib>
#include <cstring>
#include <cstdio>

#include "../require.h"
#include "Stash3.h"

using namespace std;

Stash::Stash(int Size) {
    size = Size;
    quantity = 0;
    storage = NULL;
    next = 0;
}

Stash::~Stash() {
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

    return (next-1); // Index number
}

void *Stash::fetch(int index) {
    if (index >= next || index < 0) {
        return 0; // Not out of bounds?
    }

    // Produce pointer to desired element:
    return &(storage[index*size]);
}

int Stash::count() {
    return next; // Number of elements in Stash
}

void Stash::inflate(int increase) {
    void *v = realloc(storage, (quantity+increase)*size);
    require(v != NULL); // Was it successful?
    storage = (unsigned char *) v;
    quantity += increase;
} ///: ~
