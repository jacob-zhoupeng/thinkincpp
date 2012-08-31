//: C20:MapVsHashMap.cpp
// The hash_map header is not part of the
// Standard C++ STL. It is an extension that
// is only available as part of the SGI STL:

#include <hash_map>
#include <iostream>
#include <map>
#include <ctime>

using namespace std;

int main(int argc, char* argv[]) {
    hash_map<int, int> hm;
    map<int, int> m;

    clock_t ticks = clock();
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 1000; j++) {
            m.insert(make_pair(j, j));
        }
    }
    cout << "map insertions: " << clock() - ticks << endl;

    ticks = clock();
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 1000; j++) {
            hm.insert(make_pair(j, j));
        }
    }
    cout << "hash_map insertions: " << clock() - ticks << endl;

    ticks = clock();
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 1000; j++) {
            m[j];
        }
    }
    cout << "map::operator[] lookups: " << clock() - ticks << endl;

    ticks = clock();
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 1000; j++) {
            hm[j];
        }
    }
    cout << "hash_map::operator[] lookups: " << clock() - ticks << endl;

    ticks = clock();
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 1000; j++) {
            m.find(j);
        }
    }
    cout << "map::find() lookups: " << clock() - ticks << endl;

    ticks = clock();
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 1000; j++) {
            hm.find(j);
        }
    }
    cout << "hash_map::find() lookups: " << clock() - ticks << endl;

    return 0;
} ///:~