//: C21:MergeTest.cpp
// Test merging in sorted ranges

#include <algorithm>

#include "PrintSequence.h"
#include "Generators.h"

using namespace std;

int main(int argc, char* argv[]) {
    const int sz = 15;
    int a[sz*2] = { 0 };

    // Both ranges go in the same array:
    generate(a, a + sz, SkipGen(0, 2));
    generate(a + sz, a + sz*2, SkipGen(1, 3));

    print<int>(a, a + sz, "range1", " ");
    print<int>(a + sz, a + sz*2, "range2", " ");

    int b[sz*2] = { 0 };
    merge(a, a + sz, a + sz, a + sz*2, b);
    print<int>(b, b + sz*2, "merge", " ");

    // set_union is a merge that removes duplicates
    set_union(a, a + sz, a + sz, a + sz*2, b);
    print<int>(b, b + sz*2, "set_union", " ");

    inplace_merge(a, a + sz, a + sz*2);
    print<int>(a, a + sz*2, "inplace_merge", " ");

    return 0;
} ///:~