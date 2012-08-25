//: C13:Stack11.cpp {0}
// New version of Stack

#include "Stack11.h"

void *Stack::pop() {
    if (head == NULL) {
        return NULL;
    }

    void *result = head->data;
    link *oldHead = head;
    head = head->next;
    delete oldHead;

    return result;
}

Stack::~Stack() {
    link *cursor = head;

    while (head != NULL) {
        cursor = cursor->next;
        delete head;
        head = cursor;
    }
} ///:~
