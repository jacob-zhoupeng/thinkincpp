//: C16:Nobloat.h
// Templatized INHSTAK.CPP
#ifndef NOBLOAT_H_INCLUDED
#define NOBLOAT_H_INCLUDED

#include "Stack11.h"

template<class T>
class NBStack : public Stack {
public:
    void push(T *str) {
        Stack::push(str);
    }

    T *peek() const {
        return (T *)Stack::peek();
    }

    T *pop() {
        return (T *)Stack::pop();
    }

    ~NBStack();
};

// Default to heap objects & ownership:
template<class T>
NBStack<T>::~NBStack() {
    T *top = pop();
    while (top != NULL) {
        delete top;
        top = pop();
    }
}

#endif // NOBLOAT_H_INCLUDED
