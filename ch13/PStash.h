//: C13:PStash.h
// Holds pointers instead of objects
#ifndef PSTASH_H_INCLUDED
#define PSTASH_H_INCLUDED

class PStash {
public:
    PStash() {
        quanity = 0;
        storage = NULL;
        next = 0;
    }
    // No ownership:
    ~PStash() {
        delete storage;
    }
    int add(void *element);
    void *operator[](int index) const; // Fetch
    // Number of elements in Stash:
    int count() const {
        return next;
    }
private:
    int quanity; // Number of storage spaces
    int next; // Next empty space
    // Pointer storage:
    void **storage;
    void inflate(int increase);
};

#endif // PSTASH_H_INCLUDED
