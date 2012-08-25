//: C20:DequeOverflow.cpp
// A deque is much more efficient than a vector
// when pushing back a lot of elements, since it
// doesn't require copying and destroying

#include <queue>
#include <cstdlib>

#include "Noisy.h"

using namespace std;

int main(int argc, char* argv[]) {
    int size = 100;

    if (argc >= 2) {
        size = atoi(argv[1]);
    }

    deque<Noisy> dn;
    Noisy n;

    for (int i = 0; i < size; i++) {
        dn.push_back(n);
    }

    cout << "\n cleaning up\n";

    return  0;
} ///:~

