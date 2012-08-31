//: C06:Stktst3.cpp
// {L} Stack3
// Constructors/destructors

#include <cstdio>
#include <cstdlib>
#include <cstring>

#include "../require.h"
#include "Stack3.h"

using namespace std;

int main(int argc, char *argv[]) {
    //! requireArgs(argc, 2); // File name is argument
    //! FILE *file = fopen(argv[1], "r");
    FILE *file = fopen(__FILE__, "r");
    require(file != NULL);
#define BUFSIZE (100)
    char buf[BUFSIZE];
    Stack textlines; // Constructor called here

    // Read file and store lines in the Stack:
    while (fgets(buf, BUFSIZE, file)) {
        char *string = (char *) malloc(strlen(buf) + 1);
        require(string != NULL);
        strcpy(string, buf);
        textlines.push(string);
    }

    // Pop lines from the Stack and print them:
    char *s;
    while ((s = (char *) textlines.pop()) != 0) {
        printf("%s", s);
        free(s);
    }

    return 0;
} // Destructor called here ///:~
