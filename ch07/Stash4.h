//: C07:Stash4.h
// Function overloading

#ifndef STASH4_H_INCLUDED
#define STASH4_H_INCLUDED

class Stash {
public:
    Stash(int Size); // Zero quantity
    Stash(int Size, int InitQuant);
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

#endif // STASH4_H_INCLUDED
