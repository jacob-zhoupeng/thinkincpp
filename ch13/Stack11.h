//: C13:Stack11.h
// New version of Stack
#ifndef STACK11_H_INCLUDED
#define STACK11_H_INCLUDED

#include <cstdio>

class Stack {
public:
    Stack() {
        head = NULL;
    }
    ~Stack();
    void push(void *Data) {
        head = new link(Data, head);
    }
    void *peek() const {
        return head->data;
    }
    void *pop();
private:
    struct link {
        void *data;
        link *next;
        link(void *Data, link *Next) {
            data = Data;
            next = Next;
        }
    } *head;
};

#endif // STACK11_H_INCLUDED
