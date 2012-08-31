//: C16:Sorted.h
// Template inheritance
#ifndef SORTED_H_INCLUDED
#define SORTED_H_INCLUDED

#include <cstdlib>
#include <cstring>
#include <ctime>
#include <vector>

#include "TStash.h"

template<class T>
class Sorted : public TStash<T> {
public:
    int add(T *element) {
        TStash<T>::add(element);
        bubblesort();
        return 0; // Sort moves the element
    }
private:
    void bubblesort();
};

template<class T>
void Sorted<T>::bubblesort() {
    for (int i = TStash<T>::count(); i > 0; i--) {
        for (int j = 1; j < i; j++) {
            if (*(TStash<T>::storage)[j-1] > *(TStash<T>::storage)[j]) {
                // Swap the two elements:
                T *t = (TStash<T>::storage)[j-1];
                (TStash<T>::storage)[j-1] = (TStash<T>::storage)[j];
                (TStash<T>::storage)[j] = t;
            }
        }
    }
}

// Unique random number generator:
template<int upper_bound>
class Urand {
public:
    Urand(int Recycle = 0); //! 定义时默认参数不能给出，否则编译器报错
    int operator()();
private:
    int map[upper_bound];
    int recycle;
};

template<int upper_bound>
Urand<upper_bound>::Urand(int Recycle) : recycle(Recycle) {
    memset(map, 0, upper_bound * sizeof(int));
    srand(time(NULL)); // Seed random number generator
}

template<int upper_bound>
int Urand<upper_bound>::operator()() {
    if (!memchr(map, 0, upper_bound)) {
        if (recycle) {
            memset(map, 0, sizeof(map)*sizeof(int));
        } else {
            return -1; // No more spaces left
        }
    }

    int newval;
    // Until unique value is found
    while (map[newval = rand() % upper_bound])
        NULL; //! null statement
    map[newval]++; // Set flag
    return newval;
}

#endif // SORTED_H_INCLUDED
