//: C20:IndexingVsAt.cpp
// Comparing "at()" to operator[]

#include <vector>
#include <deque>
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main(int argc, char* argv[]) {
    long count = 1000;
    int sz = 1000;

    if (argc >= 2) {
        count = std::atoi(argv[1]);
    }

    if (argc >= 3) {
        sz = std::atoi(argv[2]);
    }

    vector<int> vi(sz);
    clock_t ticks = clock();

    for (int i1 = 0; i1 < count; i1++) {
        for (int j = 0; j < sz; j++) {
            vi[j];
        }
    }

    cout << "vector[]" << clock() - ticks << endl;

    ticks = clock();

    for (int i2 = 0; i2 < count; i2++) {
        for (int j = 0; j < sz; j++) {
            vi.at(j);
        }
    }

    cout << "vector::at()" << clock() - ticks << endl;

    deque<int> di(sz);
    ticks = clock();

    for (int i3= 0; i3 < count; i3++) {
        for (int j = 0; j < sz; j++) {
            di[j];
        }
    }

    cout << "deque[]" << clock() - ticks << endl;

    ticks = clock();

    for (int i4 = 0; i4 < count; i4++) {
        for (int j = 0; j < sz; j++) {
            di.at(j);
        }
    }

    cout << "deque.at()" << clock() - ticks << endl;

    // Demonstrate at() when you go out of bounds:
    di.at(vi.size() + 1);

    return 0;
} ///:~

