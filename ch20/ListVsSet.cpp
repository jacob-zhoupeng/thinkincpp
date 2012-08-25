//: C20:ListVsSet.cpp
// Comparing list and set performance

#include <iostream>
#include <list>
#include <set>
#include <algorithm>
#include <ctime>
#include <cstdlib>

using namespace std;

class Obj {
public:
    Obj() : val(rand() % 500) {}

    friend bool operator<(const Obj& a, const Obj& b) {
        return a.val < b.val;
    }

    friend ostream& operator<<(ostream& os, const Obj& a) {
        return os << a.val;
    }
private:
    int a[20];
    int val;
};

template<class Container>
void print(Container& c) {
    typename Container::iterator it;

    for (it = c.begin(); it != c.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
};

struct ObjGen {
    Obj operator()() {
        return Obj();
    }
};

int main() {
    const int sz = 5000;
    srand(time(0));

    list<Obj> lo;
    clock_t ticks = clock();
    generate_n(back_inserter(lo), sz, ObjGen());
    lo.sort();
    //lo.unique(); //! ±àÒë²»Í¨¹ý
    cout << "list:" << clock() - ticks << endl;

    set<Obj> so;
    ticks = clock();
    generate_n(inserter(so, so.begin()), sz, ObjGen());
    cout << "set:" << clock() - ticks << endl;

    print(lo);
    print(so);
} ///:~

