//: C10:StaticMemberFunctions.cpp

class X {
public:
    X(int I = 0) : i(I) {
        // Non-static member function can access
        // static member function or data:
        j = i;
    }
    int val() const {
        return i;
    }
    static int incr() {
        //! i++; // Error: static member function
        //! cannot access non-static member data
        return ++j;
    }
    static int f() {
        //! val(); // Error: static member function
        //! cannot access non-static member function
        return incr(); // OK -- calls static
    }
private:
    int i;
    static int j; // 静态成员声明，未分配存储空间
};

//! static data此时分配空间
int X::j = 0;

int main() {
    X x;
    X *xp = &x;

    x.f();
    xp->f();
    X::f(); // Only works with static memebers

    return 0;
} ///:~
