//: C12:Opconv.cpp
// Op overloading conversion

class Three {
public:
    Three(int I = 0, int = 0) : i(I) {
        // Empty body
    }
private:
    int i;
};

class Four {
public:
    Four(int X) : x(X) {
        // Empty body
    }
    //! ºÃÆæ¹ÖµÄÓï·¨
    operator Three() const {
        return Three(x);
    }
private:
    int x;
};

void g(Three) {
    // Empty body
}

int main() {
    Four four(1);

    g(four);
    g(1); //! Calls Three(1, 0)

    return 0;
} ///:~
