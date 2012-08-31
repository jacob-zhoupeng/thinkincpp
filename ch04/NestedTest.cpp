//: C04:NestTest.cpp
// {L} Nested
// {T} NestTest.cpp
// Test of nested linked list

#include <cstdio>
#include <cstdlib>
#include <cstring>

#include "../require.h"
#include "Nested.h"

using namespace std;

int main(int argc, char *argv[]) {
    Stack textlines;
    FILE *file;
    char *s;
#define BUFSIZE (100)
    char buf[BUFSIZE];
    //! requireArgs(argc, 2); // File name is argument
    textlines.initialize();
    //! file = fopen(argv[1], "r");
    file = fopen(__FILE__, "r"); //! Add for test
    require(file != NULL);

    // Read file and store lines in the Stack:
    while (fgets(buf, BUFSIZE, file)) {
        char *string = (char *) malloc(strlen(buf) + 1);
        require(string != NULL);
        strcpy(string, buf);
        textlines.push(string);
    }

    // Pop the lines from the Stack and print them:
    while ((s = (char *) textlines.pop()) != NULL) {
        printf("%s", s);
        free(s);
    }

    textlines.cleanup();

    return 0;
} ///:~
