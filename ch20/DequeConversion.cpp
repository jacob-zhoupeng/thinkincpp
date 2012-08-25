//: C20:DequeConversion.cpp
// Reading into a Deque, converting to a vector

#include <deque>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <iterator>

#include "Noisy.h"

using namespace std;

int main(int argc, char* argv[]) {
    int size = 25;

    if (argc >= 2) {
        size = atoi(argv[1]);
    }

    deque<Noisy> d;
    ostream_iterator<Noisy> out(cout, " ");
    generate_n(back_inserter(d), size, NoisyGen());

    cout << "\n Converting to a vector(1)" << endl;
    vector<Noisy> v1(d.begin(), d.end());

    cout << "\n Converting to a vector(2)" << endl;
    vector<Noisy> v2;
    v2.reserve(d.size());
    v2.assign(d.begin(), d.end());

    cout << "\n Cleanup" << endl;

    return 0;
} ///:~

