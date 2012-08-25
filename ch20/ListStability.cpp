//: C20:ListStability.cpp
// Things don't move around in lists

#include <list>
#include <iterator>
#include <iostream>
#include <algorithm>

#include "Noisy.h"

using namespace std;

int main() {
    list<Noisy> l;

    ostream_iterator<Noisy> out(cout, " ");
    generate_n(back_inserter(l), 25, NoisyGen());
    cout << "\n Printing the list: " << endl;
    copy(l.begin(), l.end(), out);

    cout << "\n Reversing the list:" << endl;
    l.reverse();
    copy(l.begin(), l.end(), out);

    cout << "\n Storting the list:" << endl;
    l.sort();
    copy(l.begin(), l.end(), out);

    cout << "\n Swapping two elements:" << endl;
    list<Noisy>::iterator it1;
    list<Noisy>::iterator it2;
    it1 = it2 = l.begin();
    it2++;
    swap(*it1, *it2);
    cout << endl;
    copy(l.begin(), l.end(), out);

    cout << "\n Using generic reverse(): " << endl;
    reverse(l.begin(), l.end());
    cout << endl;
    copy(l.begin(), l.end(), out);

    cout << "\n Cleanup" << endl;

    return 0;
} ///:~

