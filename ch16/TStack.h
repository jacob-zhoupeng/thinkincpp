//: C16:TStack.h
// Stack using templates
#ifndef TSTACK_H_INCLUDED
#define TSTACK_H_INCLUDED

// Declaration required:
template<class T>
class TStackIterator;

template<class T>
class TStack {
public:
    TStack(int Owns = 1) : head(0), owns(Owns) {}
    ~TStack();

    void push(T *Data) {
        head = new link(Data, head);
    }

    T *peek() const {
        return head->data;
    }

    T *pop();

    int Owns() const {
        return owns;
    }

    void Owns(int newownership) {
        owns = newownership;
    }

    friend class TStackIterator<T>;

public: ////////// BC++ 5.3 bug hack??
    struct link {
        T *data;
        link *next;
        link(T *Data, link *Next) {
            data = Data;
            next = Next;
        }
    } *head;
    int owns;
};

template<class T>
T *TStack<T>::pop() {
    if (head == 0) {
        return 0;
    }

    T *result = head->data;
    link *oldHead = head;
    head = head->next;
    delete oldHead;
    return result;
}

template<class T>
TStack<T>::~TStack() {
    link *cursor = head;

    while (head != NULL) {
        cursor = cursor->next;
        // Conditional cleanup of data:
        if (owns) {
            delete head->data;
        }
        delete head;
        head = cursor;
    }
}

template<class T>
class TStackIterator {
public:
    TStackIterator(const TStack<T> &t1) : p(t1.head) {}
    TStackIterator(const TStackIterator &t1) : p(t1.p) {}

    // operator++ returns boolean indicating end:
    int operator++() {
        if (p->next) {
            p = p->next;
        } else {
            p = 0; // Indicates end if list
        }

        return int(p);
    }

    int operator++(int) {
        return operator++();
    }

    // Smart pointer:
    T *operator->() const {
        if (p == NULL) {
            return 0;
        }

        return p->data;
    }

    T *current() const {
        if (p == NULL) {
            return 0;
        }

        return p->data;
    }

    // int conversion for conditional test:
    operator int() const {
        return p != NULL ? 1 : 0;
    }
private:
    typename TStack<T>::link *p; //! 原书代码有误：TStack<T>::link *p;
};

#endif // TSTACK_H_INCLUDED
