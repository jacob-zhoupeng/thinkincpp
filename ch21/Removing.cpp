//: C21:Removing.cpp
// The removing algorithms

#include <vector>
#include <algorithm>

#include "Generators.h"
#include "PrintSequence.h"

using namespace std;

struct IsUpper {
    bool operator()(char c) {
        return c >= 'A' && c <= 'Z';
    }
};

int main(int argc, char* argv[]) {
    vector<char> v(50);
    generate(v.begin(), v.end(), CharGen());
    print<char>(v, "v", "");

    // Create a set of the characters in v:
    set<char> cs(v.begin(), v.end());
    set<char>::iterator it = cs.begin();
    vector<char>::iterator cit;

    // Step through and remove everything:
    while (it != cs.end()) {
        cit = remove(v.begin(), v.end(), *it);
        cout << *it << "[" << *cit << "] ";
        print<char>(v, "", ""); //! 有输出可以看出，被移除的元素是未定义的。
        it++;
    }

    generate(v.begin(), v.end(), CharGen());
    print<char>(v, "v", "");
    cit = remove_if(v.begin(), v.end(), IsUpper());
    print<char>(v.begin(), cit, "after remove_if", "");

    // Copying versions are not shown for remove
    // and remove_if.
    sort(v.begin(), cit);
    print<char>(v.begin(), cit, "sorted", "");

    vector<char> v2;
    unique_copy(v.begin(), cit, back_inserter(v2));
    print<char>(v2, "unique_copy", "");

    // Same behavior:
    cit = unique(v.begin(), cit, equal_to<char>());
    print<char>(v.begin(), cit, "unique", "");

    return 0;
} ///:~