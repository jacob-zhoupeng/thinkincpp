//: C03:Struct.cpp
// Demonstration of structures vs classes

class CL {
public:
    CL(int init = 0) {
        i = j = k = init;
    }
private:
    int i;
    int j;
    int k;
};

struct ST {
    int i;
    int j;
    int k;
    // Don't need to say "public" Everything is public!
    ST(int init = 0) {
        i = j = k = init;
    }
};

int main() {
    CL A(10);
    ST B(11);

    B.i = 44; // This is OK
    //! A.i = 44; // This will cause an error!

    return 0;
} ///:~
