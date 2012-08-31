//: C16:Stackt.cpp
// Test simple stack template
#include <iostream>

#include "../require.h"
#include "Stackt.h"

using namespace std;

// For interest, generate Fibonacci numbers:
int fibonacci(int N) {
    const int sz = 100;
    require(N < sz);
    static int F[sz]; // Initialized to zero
    F[0] = F[1] = 1;
    // Scan for unfilled array elements:
    int i;
    for (i = 0; i < sz; i++) {
        if (F[i] == 0) {
            break;
        }
    }

    while (i <= N) {
        F[i] = F[i-1] + F[i-2];
        i++;
    }

    return F[N];
}

int main() {
    Stackt<int> is;

    for (int i = 0; i < 20; i++) {
        is.push(fibonacci(i));
    }

    // Traverse with an iterator:
    StacktIter<int> it(is);
    for (int j = 0; j < 20; j++) {
        cout << it++ << endl;
    }

    for (int k = 0; k < 20; k++) {
        cout << is.pop() << endl;
    }

    return 0;
} ///:~
