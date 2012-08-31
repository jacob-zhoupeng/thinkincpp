//: C06:Stshtst3.cpp
// {L} STASH3_H_INCLUDED
// Constructors & destructors

#include <cstdio>

#include "../require.h"
#include "Stash3.h"

using namespace std;

#define BUFSIZE (80)

int main() {
    Stash intStash(sizeof(int));
    for (int j = 0; j < 100; j++) {
        intStash.add(&j);
    }

    FILE *file = fopen(__FILE__, "r");
    require(file != NULL);

    // Holds 80-character strings:
    Stash stringStash(sizeof(char) * BUFSIZE);
    char buf[BUFSIZE];
    while (fgets(buf, BUFSIZE, file)) {
        stringStash.add(buf);
    }
    fclose(file);

    for (int k = 0; k <intStash.count(); k++) {
        printf("intStash.fetch(%d) = %d\n", k, *(int *)intStash.fetch(k));
    }

    for (int i = 0; i < stringStash.count(); i++) {
        printf("stringStash.fetch(%d) = %s", i , (char *) stringStash.fetch(i));
    }
    putchar('\n');

    return 0;
} ///:~
