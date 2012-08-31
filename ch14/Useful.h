//: C14:Useful.h
// A class to reuse
#ifndef USEFUL_H_INCLUDED
#define USEFUL_H_INCLUDED

class X {
public:
    X() {
        i = 0;
    }
    void set(int I) {
        i = I;
    }
    int read() const {
        return i;
    }
    int permute() {
        return i = i * factor;
    }
private:
    int i;
    enum {
        factor = 11
    };
};

#endif // USEFUL_H_INCLUDED
