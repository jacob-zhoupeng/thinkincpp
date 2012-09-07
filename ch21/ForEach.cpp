//: C21:ForEach.cpp
// Use of STL for_each() algorithm
#include <iostream>
#include <vector>
#include <algorithm>

#include "Counted.h"

using namespace std;

// Simple function:
void Destroy(Counted* fp) {
    delete fp;
}

// Function object:
template<class T>
class DeleteT {
public:
    void operator()(T* x) {
        delete x;
    }
};

// Template function:
template<class T>
void wipe(T* x) {
    delete x;
}

int main(int argc, char* argv[]) {
    CountedVector A("one");
    for_each(A.begin(), A.end(), Destroy);

    CountedVector B("two");
    for_each(B.begin(), B.end(), DeleteT<Counted>());
    
    // Used to work on at least one compiler:
    // CountedVector C("three");
    // for_each(C.begin(), C.end(), wipe<Counted>);

    return 0;
} ///:~