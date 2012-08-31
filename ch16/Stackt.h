//: C16:Stackt.h
// Simple stack template
#ifndef STACKT_H_INCLUDED
#define STACKT_H_INCLUDED

template<class T> class StacktIter; // Declare

template<class T>
class Stackt {
public:
    Stackt() : top(0) {
        stack[top] = 0;
    }
    void push(const T&i) {
        if (top < ssize) {
            stack[top++] = i;
        }
    }
    T pop() {
        return stack[top > 0 ? --top : top];
    }
    friend class StacktIter<T>;
private:
    static const int ssize = 100;
    T stack[ssize];
    int top;
};

template<class T>
class StacktIter {
public:
    StacktIter(Stackt<T> &is) : s(is), index(0) {}
    T &operator++() {
        // Prefix form
        if (index < s.top-1) {
            index++;
        }
        return s.stack[index];
    }
    T &operator++(int) {
        // Postfix form
        int returnIndex = index;
        if (index < s.top - 1) {
            index++;
        }
        return s.stack[returnIndex];
    }
private:
    Stackt<T> &s;
    int index;
};

#endif // STACKT_H_INCLUDED
