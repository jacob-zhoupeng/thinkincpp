//: C20:MultiSet1.cpp
// Demonstration of multiset behavior

#include <iostream>
#include <iterator>
#include <set>
#include <algorithm>
#include <ctime>
#include <cstdlib>

using namespace std;

class X {
public:
    X(char cc, int ii) : c(cc), i(ii) {}

    // Notice no operator= is required
    friend bool operator<(const X& x, const X& y) {
        return x.c < y.c;
    }

    friend ostream& operator<<(ostream& os, X x) {
        return os << x.c << ":" << x.i;
    }
private:
    char c; // Used in comparison
    int i; // Not used in comparison

    // Don't need default constructor and operator=
    X();
    X& operator=(const X&);

    // Usually need a copy-constructor (but the
    // synthesized version works here)
};

class Xgen {
public:
    Xgen() {
        srand(time(0));
    }

    X operator()() {
        char c = 'A' + rand() % span;
        return X(c, i++);
    }
private:
    static int i;
    
    // Number of characters to select from:
    static const int span = 6;
};

int Xgen::i = 0;

typedef multiset<X> Xmset;
typedef Xmset:: const_iterator Xmit;

int main(int argc, char* argv[]) {
    Xmset mset;

    // Fill in with X's:
    generate_n(inserter(mset, mset.begin()), 25, Xgen());

    // Initialize a regular set from mset:
    set<X> unique(mset.begin(), mset.end());
    copy(unique.begin(), unique.end(), ostream_iterator<X>(cout, " "));
    cout << "\n----\n";

    // Iterate over the unique values:
    for (set<X>::iterator i = unique.begin(); i != unique.end(); i++) {
        pair<Xmit, Xmit> p = mset.equal_range(*i);
        copy(p.first, p.second, ostream_iterator<X>(cout, " "));
        cout << endl;
    }

    return 0;
} ///:~
