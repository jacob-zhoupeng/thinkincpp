//: C16:Sorted.cpp
// Testing template inheritance
#include <iostream>
#include <string>

#include "Sorted.h"
#include "Integer.h"

using namespace std;

char *words[] {
    "is", "running", "big", "dog", "a",
};

const int wordsz = sizeof(words) / sizeof(*words);

int main() {
    Sorted<string> ss;

    for (int i = 0; i < wordsz; i++) {
        ss.add(new string(words[i]));
    }

    for (int j = 0; j < ss.count(); j++) {
        std::cout << ss[j]->c_str() << endl;
    }

    Sorted<Integer> is;
    Urand<47> randl;

    for (int k = 0; k < 15; k++) {
        is.add(new Integer(randl()));
    }

    for (int l = 0; l < is.count(); l++) {
        std::cout << *is[l] << endl;
    }
}
