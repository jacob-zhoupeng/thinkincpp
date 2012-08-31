//: C07:Stash4.cpp {0}
// Function overloading

#include <cstdlib>
#include <cstring>
#include <cstdio>

#include "../require.h"
#include "Stash4.h"

using namespace std;

Stash::Stash(int Size) {
    size = Size;
    quantity = 0;
    next = 0;
    storage = NULL;
}

Stash::Stash(int Size, int InitQuant) {
    size = Size;
    quantity = 0;
    next = 0;
    storage = NULL;
    inflate(InitQuant);
}

Stash::~Stash() {
    if (storage != NULL) {
        puts("freeing storage");
        free(storage);
    }
}

int Stash::add(void *element) {
    if (next >= quantity) { // Enough space left?
        inflate(100); // Add space for 100 elements
    }
    // Copy element into storage, starting at next empty space:
    memcpy(&(storage[next*size]), element, size);
    next++;

    return (next-1); // Index number
}

void *Stash::fetch(int index) {
    if (index >= next || index < 0) {
        return NULL; // Not out of bounds?
    }
    // Produce pointer to desired element:
    return &(storage[index*size]);
}

int Stash::count() {
    return next; // Number of elements in Stash
}

void Stash::inflate(int increase) {
    void *v = realloc(storage, (quantity+increase)*size);
    require(v != NULL); // Was is successful?
    storage = (unsigned char *) v;
    quantity += increase;
} ///:~
