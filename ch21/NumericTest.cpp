//: C21:NumericTest.cpp
#include <numeric>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <functional>

#include "PrintSequence.h"

using namespace std;

int main(int argc, char* argv[]) {
    int a[] = { 1, 1, 2, 2, 3, 5, 7, 9, 11, 13 };
    const int asz = sizeof(a)/sizeof(a[0]);

    print<int>(a, a + asz, "a", " ");

    int r = accumulate(a, a + asz, 0);
    cout << "accumulate 1: " << r << endl;

    // Should produce the same result:
    r = accumulate(a, a + asz, 0, plus<int>());
    cout << "accumulate 2: " << r << endl;

    int b[] = { 1, 2, 3, 4, 1, 2, 3, 4, 1, 2 };
    print<int>(b, b + sizeof(b)/sizeof(b[0]), "b", " ");

    r = inner_product(a, a + asz, b, 0);
    cout << "inner_product 1: " << r << endl;

    // Should produce the same result:
    r = inner_product(a, a + asz, b, 0, plus<int>(), multiplies<int>());
    cout << "inner_product 2: " << r << endl;

    int* it = partial_sum(a, a + asz, b);
    print<int>(b, it, "partial_sum 1", " ");

    // Should produce the same result:
    it = partial_sum(a, a + asz, b, plus<int>());
    print<int>(b, it, "partial_sum 2", " ");

    it = adjacent_difference(a, a + asz, b);
    print<int>(b, it, "adjacent_difference 1", " ");

    // Should produce the same result:
    it = adjacent_difference(a, a + asz, b, minus<int>());
    print<int>(b, it, "adjacent_difference 2", " ");

    return 0;
} ///:~