//: C04:Libtest.cpp
// {L} Libcpp
// Test of C++ library

#include <cstdio>

#include "../require.h"
#include "Libcpp.h"

using namespace std;

#define BUFSIZE (80)

int main() {
    Stash intStash;
    Stash stringStash;
    int i;
    FILE *file;
    char buf[BUFSIZE];
    char *cp;

    //...
    intStash.initialize(sizeof(int));
    for (i = 0; i < 100; i++) {
        intStash.add(&i);
    }

    // Holds 80-character strings:
    stringStash.initialize(sizeof(char)*BUFSIZE);
    file = fopen(__FILE__, "r");
    require(file != NULL);
    while (fgets(buf, BUFSIZE, file)) {
        stringStash.add(buf);
    }
    fclose(file);

    for (i = 0; i < intStash.count(); i++) {
        printf("intStash.fetch(%d) = %d\n", i, *(int *)intStash.fetch(i));
    }

    i = 0;
    while ((cp = (char *)stringStash.fetch(i++)) != NULL) {
        printf("stringStash.fetch(%d) = %s", i-1, cp);
    }
    putchar('\n');

    intStash.cleanup();
    stringStash.cleanup();

    return 0;
} ///: ~
