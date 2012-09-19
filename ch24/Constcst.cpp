//: C24:Constcst.cpp
// Const casts

int main(int argc, char* argv[]) {
    const int i = 0;
    
    int* j = (int*)&i; // Deprecated form
    j = const_cast<int*>(&i); // Preferred

    // Can't do simulateneous additional casting:
    //! long* l = const_cast<long*>(&i); // Error

    volatile int k = 0;
    int* u = const_cast<int*>(&k);

    return 0;
}

class X {
public:
    void f() const {
        // Casting away const-ness:
        (const_cast<X*>(this))->i = 1;
    }
protected:
    int i;
    // mutable int i; // A better approach
}; ///:~