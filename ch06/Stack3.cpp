//: C06:Stack3.cpp {0}
// Constructors/destructors

#include <cstdlib>

#include "../require.h"
#include "Stack3.h"

using namespace std;

void Stack::link::initialize(void *Data, link *Next) {
    data = Data;
    next = Next;
}

Stack::Stack() {
    head = NULL;
}

void Stack::push(void *Data) {
    // Can't we use a constructor with malloc!
    link *newlink = (link *) malloc(sizeof(link));
    require(newlink);
    newlink->initialize(Data, head);
    head = newlink;
}

void *Stack::peek() {
    return head->data;
}

void *Stack::pop() {
    if (head == NULL) {
        return NULL;
    }
    void *result = head->data;
    link *oldHead = head;
    head = head->next;
    free(oldHead);

    return result;
}

Stack::~Stack() {
    link *cursor = head;
    while (head != NULL) {
        cursor = cursor->next;
        free(head->data); // Assumes malloc!
        free(head);
        head = cursor;
    }
} ///:~
