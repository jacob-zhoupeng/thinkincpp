//: C03:Simple.h
// Simple class that prevents re-definition

#ifndef SIMPLE_H_INCLUDED
#define SIMPLE_H_INCLUDED

class Simple {
public:
    Simple() {
        i = j = k = 0;
    }
private:
    int i;
    int j;
    int k;
};

#endif // SIMPLE_H_INCLUDED///:~
