//: C05:Stack.h
// Nested structs via linked list

#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

class Stack {
public:
    void initialize();
    void push(void *Data);
    void *peek();
    void *pop();
    void cleanup();
private:
    struct link {
        void *data;
        link *next;
        void initialize(void *Data, link *Next);
    } *head;
};

#endif // STACK_H_INCLUDED
