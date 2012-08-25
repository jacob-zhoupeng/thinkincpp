//: C05:Stash.h
// Converted to use access control

#ifndef STASH_H_INCLUDED
#define STASH_H_INCLUDED

class Stash {
public:
    void initialize(int Size);
    void cleanup();
    int add(void *element);
    void *fetch(int index);
    int count();
private:
    int size; // Size of each space
    int quantity; // Number of storage spaces
    int next; // Next empty space
    // Dynamically allocated array of bytes:
    unsigned char *storage;
    void inflate(int increase);
};

#endif // STASH_H_INCLUDED
