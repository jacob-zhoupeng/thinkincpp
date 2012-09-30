//: C26:Memcheck.cpp {O}
// Memory allocation tester
#include <cstdlib>
#include <cstring>
#include <cstdio>

using namespace std;

// MEMCHECK.H must not be included here

// Output file object using stdio.h.
// (cout constructor calls malloc())
class OFile {
public:
    OFile(char* name) : f(fopen(name, "w")) {}

    ~OFile() {
        fclose(f);
        f = 0;
    }

    operator FILE*() {
        return f;
    }
private:
    FILE* f;
};

extern OFile memtrace;

// Comment out the following to send all the
// information to the trace file:
#define memtrace stdout

const unsigned long _pool_sz = 50000L;
static unsigned char _memory_pool[_pool_sz];
static unsigned char* _pool_ptr = _memory_pool;

void* getmem(size_t sz) {
    if (_memory_pool + _pool_sz - _pool_ptr < sz) {
        fprintf(stderr, "Out of memory, Use bigger model\n");
        exit(1);
    }
    
    void* p = _pool_ptr;
    _pool_ptr += sz;
    return p;
}

// Holds information about allocated pointers:
class MemBag {
public:
    enum type {
        Malloc, New
    };

    MemBag() : v(0), sz(0), next(0) {}

    void* add(void* P, type T = Malloc, char* S = "library", int L = 0) {
        if (next >= sz) {
            sz += increment;

            // This memory is never freed, so it
            // doesn't "get involved" in the test:
            const int memsize = sz * sizeof(m);

            // Equivalent of realloc, no registration:
            void* p = getmem(memsize);
            if (v) {
                memmove(p, v, memsize);
            }
            v = (m*)p;
            memset(&v[next], 0, increment * sizeof(m));
        }
        v[next++] = m(P, T, S, L);
        return P;
    }

    // Print information about allocation:
    void allocation(int i) {
        fprintf(memtrace, "pointer %p allocated with %s", v[i].mp, 
            typestr(v[i].t));
        if (v[i].t == New) {
            fprintf(memtrace, " at %s: %d", v[i].file, v[i].line);
        }
        fprintf(memtrace, "\n");
    }

    void validate(void* p, type T = Malloc) {
        for (int i = 0; i < next; i++) {
            if (v[i].mp == p) {
                if (v[i].t != T) {
                    allocation(i);
                    fprintf(memtrace, "\t was released as if it were "
                        "allocated with %s \n", typestr(T));
                }
            }
            v[i].mp = 0; // Erase it
            return;
        }
        fprintf(memtrace, "pointer not in memory list: %p\n", p);
    }

    ~MemBag() {
        for (int i = 0; i < next; i++) {
            if (v[i].mp != 0) {
                fprintf(memtrace, "pointer not released: ");
                allocation(i);
            }
        }
    }
private:
    char* typestr(type t) {
        switch(t) {
            case Malloc : 
                return "malloc";
            case New : 
                return "new";
            default :
                return "?unknown?";
        }
    }

    struct m {
        void* mp; // Memory pointer
        type t; // Allocation type
        char* file; // File name where allocated
        int line; // Line number where allocated

        m(void* v, type T, char* F, int L) 
            : mp(v), t(T), file(F), line(L) {}
    }* v;

    int sz;
    int next;
    enum {
        increment = 50
    };
};

extern MemBag MEMBAG_;

void* malloc(size_t sz) {
    void* p = getmem(sz);
    return MEMBAG_.add(p, MemBag::Malloc);
}

void* calloc(size_t num_elems, size_t elem_sz) {
    void* p = getmem(num_elems * elem_sz);
    memset(p, 0, num_elems * elem_sz);
    return MEMBAG_.add(p, MemBag::Malloc);
}

void* realloc(void* block, size_t sz) {
    void* p = getmem(sz);
    if (block) {
        memmove(p, block, sz);
    }
    return MEMBAG_.add(p, MemBag::Malloc);
}

void free(void* v) {
    MEMBAG_.validate(v, MemBag::Malloc);
}

void* operator new(size_t sz) {
    void* p = getmem(sz);
    return MEMBAG_.add(p, MemBag::New);
}

void* operator new(size_t sz, char* file, int line) {
    void* p = getmem(sz);
    return MEMBAG_.add(p, MemBag::New, file, line);
}

void operator delete(void* v) {
    MEMBAG_.validate(v, MemBag::New);
}

MemBag MEMBAG_;

// Placed here so the constructor is called
// AFTER that of MEMBAG_ :

#ifdef memtrace
#undef memtrace
#endif

OFile memtrace("memtrace.out");
// Causes 1 "pointer not in memory list" message
///:~