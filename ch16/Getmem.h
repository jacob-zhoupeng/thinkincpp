//: C16:Getmem.h
// Function template for memory
#ifndef GETMEM_H_INCLUDED
#define GETMEM_H_INCLUDED

#include <cstdlib>
#include <cstring>

#include "../require.h"

template<class T>
void getmem(T *&oldmem, int elems) { //! 指针的引用
    typedef int cntr; // Type of element counter
    const int csz = sizeof(cntr); // And size
    const int Tsz = sizeof(T);

    if (elems == 0) {
        free(&(((cntr *)oldmem)[-1]));
        return;
    }

    T *p = oldmem;
    cntr oldcount = 0;
    if (p != NULL) { // Previously allocated memory
        ((cntr *) p)--; // Back up by one cntr
        oldcount = *(cntr *)p; // Previous # elems
    }
    T *m = (T *) realloc(p, elems*Tsz + csz);
    require(m != 0);
    *((cntr *) m) = elems; // Keep track of count
    const cntr increment = elems - oldcount;
    if (increment > 0) {
        // Starting address of data:
        long startadr = (long) &(m[oldcount]);
        startadr += csz;
        // Zero the additional new memory:
        memset((void *)startadr, 0, increment*Tsz);
    }
    // Return the address beyond the count:
    oldmem = (T *) (&(((cntr *)m)[1]));
}

template<class T>
inline void freemem(T *m) {
    getmem(m, 0);
}

#endif // GETMEM_H_INCLUDED
