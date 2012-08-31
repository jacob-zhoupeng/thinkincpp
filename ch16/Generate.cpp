//: C16:Generate.cpp
// Explicit instantiation
#include <iostream>

#include "Sorted.h"
#include "Integer.h"

using namespace std;

// Explicit instantiation:
template class Sorted<Integer>;

int main() {
    Sorted<Integer> is;
    Urand<47> randl;

    for (int k = 0; k < 15; k++) {
        is.add(new Integer(randl()));
    }

    for (int l = 0; l < is.count(); l++) {
        cout << *is[l] << endl;
    }

    return 0;
} ///:~
