//: C16:IStack.cpp
// Simple integer stack
#include <iostream>

#include "../require.h"

using namespace std;

class IStack {
public:
    IStack() :top(0) {
        stack[top] = 0;
    }
    void push(int i) {
        if (top < ssize) {
            stack[top++] = i;
        }
    }
    int pop() {
        return stack[top > 0 ? --top : top];
    }
    friend class IStackIter;
private:
    enum {
        ssize = 100
    };
    int stack[ssize];
    int top;
};

// An iterator is a "super-pointer"
class IStackIter {
public:
    IStackIter(IStack &is) : S(is), index(0) {}
    int operator++() {
        // Prefix form
        if (index < S.top - 1) {
            index++;
        }
        return S.stack[index];
    }
    int operator++(int) {
        // Postfix form
        int returnval = S.stack[index];
        if (index < S.top - 1) {
            index++;
        }
        return returnval;
    }
private:
    IStack &S;
    int index;
};

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
    IStack is;
    for (int i = 0; i < 20; i++) {
        is.push(fibonacci(i));
    }
    // Traverse with an iterator:
    IStackIter it(is);
    for (int j = 0; j < 20; j++) {
        cout << it++ << endl;
    }
    for (int k = 0; k < 20; k++) {
        cout << is.pop() << endl;
    }

    return 0;
} ///:~
