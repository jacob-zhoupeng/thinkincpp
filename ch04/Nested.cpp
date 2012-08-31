//: C04:Nested.cpp {0}
// Linked list with nesting

#include <cstdlib>

#include "Nested.h"
#include "../require.h"

using namespace std;

void Stack::link::initialize(void *Data, link *Next) {
    data = Data;
    next = Next;
}

void Stack::initialize() {
    head = NULL;
}

void Stack::push(void *Data) {
    link *newlink = (link *) malloc(sizeof(link));
    require(newlink != NULL);
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

void Stack::cleanup() {
    link *cursor = head;

    while (head != NULL) {
        cursor = cursor->next;
        free(head->data); // Assumes a malloc!
        free(head);
        head = cursor;
    }
}
