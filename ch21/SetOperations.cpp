//: C21:SetOperations.cpp
// Set operations on sorted ranges

#include <vector>
#include <algorithm>

#include "Generators.h"
#include "PrintSequence.h"

using namespace std;

int main(int argc, char* argv[]) {
    vector<char> v(50);
    vector<char> v2(50);

    CharGen g;

    generate(v.begin(), v.end(), g);
    generate(v2.begin(), v2.end(), g);

    sort(v.begin(), v.end());
    sort(v2.begin(), v2.end());

    print<char>(v, "v", "");
    print<char>(v2, "v2", "");

    bool b = includes(v.begin(), v.end(), v.begin() + v.size()/2, v.end());
    cout << "includes: " << (b ? "true" : "false") << endl;

    vector<char> v3;
    vector<char> v4;
    vector<char> v5;
    vector<char> v6;

    set_union(v.begin(), v.end(), v2.begin(), 
        v2.end(), back_inserter(v3));
    print<char>(v3, "set_union", "");

    set_intersection(v.begin(), v.end(), v2.begin(), 
        v2.end(), back_inserter(v4));
    print<char>(v4, "set_intersection", "");

    set_difference(v.begin(), v.end(), v2.begin(), 
        v2.end(), back_inserter(v5));
    print<char>(v5, "set_difference", "");

    set_symmetric_difference(v.begin(), v.end(), 
        v2.begin(), v2.end(), back_inserter(v6));
    print<char>(v6, "set_symmetric_difference", "");
    
    return 0;
} ///:~