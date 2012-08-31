//: C10:Depend.h
// Static initialization technique
#ifndef DEPEND_H_INCLUDED
#define DEPEND_H_INCLUDED

#include <iostream>

extern int x; // Declarations, not definitions
extern int y;

class Initializer {
public:
    Initializer() {
        std::cout << "Initializer()" << std::endl;
        // Initialize first time only
        if (init_cout++ == 0) {
            std::cout << "performing initialization" << std::endl;
            x = 100;
            y = 200;
        }
    }
    ~Initializer() {
        std::cout << "~Initializer()" << std::endl;
        // Clean up last time only
        if (--init_cout == 0) {
            std::cout << "performing cleanup" << std::endl;
            // Any necessary cleanup here
        }
    }
private:
    static int init_cout;
};

// The following creates one object in each
// file where DEPEND.H is included, but that
// object is only visible within that file:
static Initializer init;

#endif // DEPEND_H_INCLUDED
