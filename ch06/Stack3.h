//: C06:Stack3.h
// With constructors/destructors

#ifndef STACK3_H_INCLUDED
#define STACK3_H_INCLUDED

class Stack {
public:
    Stack();
    ~Stack();
    void push(void *Data);
    void *peek();
    void *pop();
private:
    struct link {
        void *data;
        link *next;
        void initialize(void *Data, link *Next);
    } *head;
};

#endif // STACK3_H_INCLUDED ///:~
