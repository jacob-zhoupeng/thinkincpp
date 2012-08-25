//: C04:Nested.h
// Nested struct in linked list

#ifndef NESTED_H_INCLUDED
#define NESTED_H_INCLUDED

struct Stack {
    struct link {
        void *data;
        link *next;
        void initialize(void *Data, link *Next);
    } *head;

    void initialize();
    void push(void *Data);
    void *peek();
    void *pop();
    void cleanup();
};

#endif // NESTED_H_INCLUDED
