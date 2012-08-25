//: C05:Handle.h
// Handle classes

#ifndef HANDLE_H_INCLUDED
#define HANDLE_H_INCLUDED

class Handle {
public:
    void initialize();
    void cleanup();
    int read();
    void change(int);
private:
    struct cheshire; // Class declaration only
    cheshire *smile;
};

#endif // HANDLE_H_INCLUDED
