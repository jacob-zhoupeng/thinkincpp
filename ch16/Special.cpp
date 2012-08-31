//: C16:Special.cpp
// Template specialization
// A special sort for char*
#include <iostream>

#include "Sorted.h"

using namespace std;

class Sorted<char> : public TStash<char> {
public:
    int add(char *element) {
        TStash<char>::add(element);
        bubblesort();
        return 0; // Sort moves the element
    }
private:
    void bubblesort();
};

void Sorted<char>::bubblesort() {
    for (int i = count(); i > 0; i--) {
        for (int j = 1; j < i; j++) {
            if (strcmp(storage[j], storage[j-1]) < 0) {
                // Swap the two elements:
                char *t = storage[j-1];
                storage[j-1] = storage[j];
                storage[j] = t;
            }
        }
    }
}

char *words[] = {
    "is", "running", "big", "dog", "a",
};

const int wsz = sizeof(words) / sizeof(*words);

int main() {
    Sorted<char> sc;

    for (int k = 0; k < wsz; k++) {
        sc.add(words[k]);
    }

    for (int l = 0; l < sc.count(); l++) {
        cout << sc[l] << endl;
    }

    return 0;
} ///:~
