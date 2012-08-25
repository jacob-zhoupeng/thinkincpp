/*: C04:Lib.h Header file: example C library */
/* Array-like entity created at run-time */

#ifndef LIB_H_INCLUDED
#define LIB_H_INCLUDED

typedef struct STASHtag {
    int size; /* Size of each space */
    int quantity; /* Number of storage spaces */
    int next; /* Next empty space */
    /* Dynamically allocated array of bytes: */
    unsigned char *storage;
} stash;

void initialize(stash *S, int Size);
void cleanup(stash *S);
int add(stash *S, void *element);
void *fetch(stash *S, int index);
int count(stash *S);
void inflate(stash *S, int increase);
/* ///:~ */

#endif // LIB_H_INCLUDED
