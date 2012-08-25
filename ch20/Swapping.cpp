//: C20:Swapping.cpp
// All basic sequence containers can be swapped

#include <list>
#include <vector>
#include <deque>
#include <iostream>
#include <iterator>
#include <algorithm>

#include "Noisy.h"

using namespace std;

ostream_iterator<Noisy> out(cout, " ");

template<class Cont>
void print(Cont& c, char* comment = "") {
    cout << "\n" << comment << ": ";
    copy(c.begin(), c.end(), out);
    cout << endl;
}

template<class Cont>
void testSwap(char* cname) {
    Cont c1;
    Cont c2;

    generate_n(back_inserter(c1), 10, NoisyGen());
    generate_n(back_inserter(c2), 5, NoisyGen());

    cout << "\n" << cname << ":" << endl;
    print(c1, "c1");
    print(c2, "c2");

    cout << "\n Swapping the " << cname << ":" << endl;
    c1.swap(c2);
    print(c1, "c1");
    print(c2, "c2");
}

int main() {
    testSwap<vector<Noisy> >("vector");
    testSwap<deque<Noisy> >("deque");
    testSwap<list<Noisy> >("list");

    return 0;
} ///:~

