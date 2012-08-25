//: C20:VectorOverflow.cpp
// Shows the copy-construction and destruction
// That occurs when a vector must reallocate
// (It maintains a linear array of elements)

#include <vector>
#include <iostream>
#include <string>
#include <cstdlib>

#include "Noisy.h"

using namespace std;

int main(int argc, char* argv[]) {
    int size = 10000;
    if (argc >= 2) {
        size = atoi(argv[1]);
    }

    vector<Noisy> vn;
    Noisy n;
    for (int i = 0; i < size; i++) {
        vn.push_back(n);
    }
    cout << "\n cleaning up\n";

    return 0;
} ///:~

