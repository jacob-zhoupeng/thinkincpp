//: C06:Stash3.h
// With constructors & destructors

#ifndef STASH3_H_INCLUDED
#define STASH3_H_INCLUDED

class Stash {
public:
    Stash(int Size);
    ~Stash();
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

#endif // STASH3_H_INCLUDED
