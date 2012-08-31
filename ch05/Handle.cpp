//: C05:Handle.cpp {0}
// Handle implementation

#include <cstdlib>

#include "../require.h"
#include "Handle.h"

using namespace std;

// Define Handle's implementation:
struct Handle::cheshire {
    int i;
};

void Handle::initialize() {
    smile = (cheshire *) malloc(sizeof(cheshire));
    require(smile != NULL);
    smile->i = 0;
}

void Handle::cleanup() {
    free(smile);
}

int Handle::read() {
    return smile->i;
}

void Handle::change(int x) {
    smile->i = x;
} ///:~
