/*: C04:Libtestc.c */
// {L} Lib
/* Test demonstration library */

#include <stdio.h>
#include <assert.h>
#include "Lib.h"

#define BUFSIZE (80)

int main() {
    stash intStash;
    stash stringStash;
    int i = 0;
    FILE *file = NULL;
    char buf[BUFSIZE];
    char *cp = NULL;

    /* .... */
    initialize(&intStash, sizeof(int));
    for (i = 0; i < 100; i++) {
        add(&intStash, &i);
    }

    /* Holds 80-character strings: */
    initialize(&stringStash, sizeof(char) * BUFSIZE);
    file = fopen(__FILE__, "r");
    assert(file != NULL);
    while (fgets(buf, BUFSIZE, file)) {
            add(&stringStash, buf);
    }
    fclose(file);

    for (i = 0; i < count(&intStash); i++) {
        printf("fetch(&intStash, %d) = %d\n", i, *(int *)fetch(&intStash, i));
    }

    i = 0;
    while ((cp = fetch(&stringStash, i++)) != NULL) {
        printf("fetch(&stringStash, %d) = %s", i-1, cp);
    }
    putchar('\n');

    cleanup(&intStash);
    cleanup(&stringStash);

    return 0;
}
