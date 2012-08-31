//: C13:PStash.cpp {0}
// Pointer Stash definitions

#include <iostream>
#include <cstring> // Mem functions

#include "PStash.h"

using namespace std;

int PStash::add(void *element) {
    const int InflateSize = 10;

    if (next >= quanity) {
        inflate(InflateSize);
    }
    storage[next++] = element;
    return (next - 1); // Index number
}

// Operator overlaoding replacement for fetch
void *PStash::operator[](int index) const {
    if (index >= next || index < 0) {
        return NULL; // Out of bounds
    }
    // Produce pointer to desired element:
    return storage[index];
}

void PStash::inflate(int increase) {
    const int psz = sizeof(void *);

    // realloc() is cleaner than this:
    void **st = new void*[quanity + increase];
    memset(st, 0, (quanity+increase) * psz);
    memcpy(st, storage, quanity * psz);
    quanity += increase;
    delete storage; // Old storage
    storage = st; // Point to new memory
} ///:~
