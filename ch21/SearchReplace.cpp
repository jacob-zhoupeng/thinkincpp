//: C21:SearchReplace.cpp
// The STL search and replace algorithms

#include <vector>
#include <algorithm>
#include <functional>

#include "PrintSequence.h"

using namespace std;

struct PlusOne {
    bool operator()(int i, int j) {
        return j == i + 1;
    }
};

class MulMoreThan {
public:
    MulMoreThan(int val) : value(val) {}

    //! 这里原代码是，编译出错: bool operator(int v, int m)，修改为如下
    bool operator()(int v, int m) {
        return v * m > value;
    }
private:
    int value;
};

int main(int argc, char* argv[]) {
    int a[] = { 1, 2, 3, 4, 5, 6, 6, 7, 7, 7, 8, 8, 8, 8, 11, 11, 11, 11, 11 };
    const int asz = sizeof(a)/sizeof(*a);

    vector<int> v(a, a + asz);
    print<int>(v, "v", " ");
    vector<int>::iterator it = find(v.begin(), v.end(), 4);
    cout << "find: " << *it << endl;
    
    it = find_if(v.begin(), v.end(), bind2nd(greater<int>(), 8));
    cout << "find_if: " << *it << endl;

    it = adjacent_find(v.begin(), v.end());
    while (it != v.end()) {
        cout << "adjacent_find: " << *it << ", " << *(it + 1) << endl;
        it = adjacent_find(it + 2, v.end());
    }

    it = adjacent_find(v.begin(), v.end(), PlusOne());
    while (it != v.end()) {
        cout << "adjacent_find PlusOne: " << *it << ", " <<*(it + 1) << endl;
        it = adjacent_find(it + 1, v.end(), PlusOne());
    }

    int b[] = { 8, 11 };
    const int bsz = sizeof(b)/sizeof(*b);
    print<int>(b, b + bsz, "b", " ");
    
    it = find_first_of(v.begin(), v.end(), b, b + bsz);
    print<int>(it, it + bsz, "find_first_if", " ");

    /*
    it = find_first_of(v.begin(), v.end(), b, b + bsz, PlusOne());
    print<int>(it, it + bsz, "find_first_if PlusOne", " ");
     */

    it = search(v.begin(), v.end(), b, b + bsz);
    print<int>(it, it + bsz, "search", " ");

    int c[] = { 5, 6, 7 };
    const int csz = sizeof(c)/sizeof(*c);
    print<int>(c, c + csz, "c", " ");

    it = search(v.begin(), v.end(), c, c + csz, PlusOne());
    print<int>(it, it + csz, "search PlusOne", " ");

    int d[] = { 11, 11, 11 };
    const int dsz = sizeof(d)/sizeof(*d);
    print<int>(d, d + dsz, "d", " ");

    it = find_end(v.begin(), v.end(), d, d + dsz);
    print<int>(it, v.end(), "find_end", " ");

    int e[] = { 9, 9 };
    print<int>(e, e + 2, "e", " ");

    it = find_end(v.begin(), v.end(), e, e + 2, PlusOne());
    print<int>(it, v.end(), "find_end PlusOne", " ");

    it = search_n(v.begin(), v.end(), 3, 7);
    print<int>(it, it + 3, "search_n 3, 7", " ");

    it = search_n(v.begin(), v.end(), 6, 15, MulMoreThan(100));
    print<int>(it, it + 6, "search_n 6, 15, MulMoreThan(100)", " ");
    
    cout << "min_element: " << *min_element(v.begin(), v.end()) << endl;
    cout << "max_element: " << *max_element(v.begin(), v.end()) << endl;

    vector<int> v2;

    replace_copy(v.begin(), v.end(), back_inserter(v2), 8, 47);
    print<int>(v2, "replace copy 8 -> 47", " ");

    replace_if(v.begin(), v.end(), bind2nd(greater_equal<int>(), 7), -1);
    print<int>(v, "replace_if >= 7 -> -1", " ");

    return 0;
} ///:~