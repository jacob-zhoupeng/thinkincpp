//: C20:RawStorageIterator.cpp
// Demonstrate the raw_storage_iterator

#include <iostream>
#include <iterator>
#include <algorithm>
#include <memory>

#include "Noisy.h"

using namespace std;

int main() 
{
    const int quantity = 10;

    // Create raw storage and cast to desired type:
    Noisy* np = (Noisy*) new char[quantity * sizeof(Noisy)];

    raw_storage_iterator<Noisy*, Noisy> rsi(np);

    for (int i = 0; i < quantity; i++) 
    {
        *rsi++ = Noisy(); // Place objects in storage
    }
    cout << endl;

    copy(np, np + quantity, ostream_iterator<Noisy>(cout, " "));
    cout << endl;

    // Explicit destructor call for cleanup:
    for (int j = 0; j < quantity; j++) {
        (&np[j])->~Noisy();
    }

    // Release raw storage:
    delete (char*)np;

    return 0;
} ///:~

