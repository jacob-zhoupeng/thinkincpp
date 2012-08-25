//: C04:Libcpp.h
// C library converted to C++

#ifndef LIBCPP_H_INCLUDED
#define LIBCPP_H_INCLUDED

struct Stash {
    int size; // Size of each space
    int quantity; // Number of storage spaces
    int next; // Next empty space
    // Dynamically allocated array of bytes:
    unsigned char *storage;

    // Functions!
    void initialize(int Size);
    void cleanup();
    int add(void *element);
    void *fetch(int index);
    int count();
    void inflate(int increase);
}; ///:~

#endif // LIBCPP_H_INCLUDED
