//: C07:Stshtst4.cpp
// {L} Stash4
// Function overloading

#include <cstdio>

#include "../require.h"
#include "Stash4.h"

using namespace std;

#define BUFSIZE (80)

int main() {
    int i;
    FILE *file;
    char buf[BUFSIZE];
    char *cp;
    // ....
    Stash intStash(sizeof(int));
    for (i = 0; i < 100; i++) {
        intStash.add(&i);
    }
    file = fopen(__FILE__, "r");
    require(file != NULL);

    // Holds 80-character strings:
    Stash stringStash(sizeof(char) * BUFSIZE);
    while(fgets(buf, BUFSIZE, file)) {
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

    return 0;
} ///:~
