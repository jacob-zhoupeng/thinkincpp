//: C06:Nojump.cpp {0}
// Can't jump past constructors

class X {
public:
    X() {}
};

void f(int i) {
    if (i < 10) {
        //! goto jump1; // Error: goto bytpasses init
    }

    X x1; // Constructor called here

jump1:
    switch(i) {
    case 1:
        X x2; // constructor called here
        break;
    //! case 2: // Error: case bypasses init
        X x3; // Constructor called here
        break;

    }
} ///:~
