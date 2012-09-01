//: C21:Counting.cpp
// The counting algorithms

#include <vector>
#include <algorithm>
#include <iterator>

#include "Generators.h"
#include "PrintSequence.h"

using namespace std;

int main(int argc, char* argv[]) {
    vector<char> v;
    generate_n(back_inserter(v), 50, CharGen());
    print<char>(v, "v", "");

    // Create a set of the characters in v:
    set<char> cs(v.begin(), v.end());
    set<char>::iterator it = cs.begin();

    while (it != cs.end()) {
        int n = count(v.begin(), v.end(), *it);
        cout << *it << ":" << n << ", ";
        it++;
    }
    
    int lc = count_if(v.begin(), v.end(), bind2nd(greater<char>(), 'a'));
    cout << "\nLowercase letters: " << lc << endl;

    sort(v.begin(), v.end());
    print<char>(v, "sorted", "");

    return 0;
} ///:~