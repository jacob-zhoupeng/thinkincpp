//: C09:Cpptime.cpp
// Testing a simple time class

#include <iostream>

#include "Cpptime.h"

using namespace std;

int main() {
    Time start;

    for (int i = 1; i < 50000; i++) {
        cout << i << ' ';
        if (i % 10 == 0) {
            cout << endl;
        }
    }

    Time end;

    cout << endl;
    cout << "start = " << start.ascii();
    cout << "end = " << end.ascii();
    cout << "delta = " << end.delta(&start);

    return 0;
} ///:~
