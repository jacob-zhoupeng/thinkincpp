/*: C04:Lib.c {0} */
/* Implemention of example C library */

/* Declare structure and functions: */
#include "Lib.h"
#include <assert.h> /* Error testing macros: */
#include <stdlib.h> /* Dynamical memory allocation functions: */
#include <string.h> /* memcpy() */
#include <stdio.h>

void initialize(stash* S, int Size) {
    S->size = Size;
    S->quantity = 0;
    S->storage = NULL;
    S->next = 0;
}

void cleanup(stash *S) {
    if (S->storage != NULL) {
        puts("freeing storage");
        free(S->storage);
    }
}

int add(stash *S, void *element) {
    /* enough space left? */
    if (S->next >= S->quantity) {
        inflate(S, 100);
    }
    /* Copy element into storage, starting at next empty space: */
    memcpy(&(S->storage[S->next * S->size]), element, S->size);
    S->next++;

    return (S->next - 1); /* Index number */
}

void *fetch(stash *S, int index) {
    if (index >= S->next || index < 0) {
        return 0; /* Not out of bounds? */
    }

    /* Produce pointer to desired element: */
    return &(S->storage[index * S->size]);
}

int count(stash *S) {
    /* Number of elements in stash */
    return S->next;
}

void inflate(stash *S, int increase) {
    void *v = realloc(S->storage, (S->quantity + increase) * S->size);
    /* Was it successful? */
    assert(v != NULL);
    S->storage = v;
} /* ///:~ */
