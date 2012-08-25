//: C09:Hidden.cpp
// Hidden activites in inlines

#include <iostream>

using namespace std;

class Member {
public:
    Member(int x = 0) {
        i = j = k = x;
    }
    ~Member() {
        cout << "~Member" << endl;
    }
private:
    int i;
    int j;
    int k;
};

class WithMembers {
public:
    WithMembers(int I) : i(I) {
        // Trivial?
    }
    ~WithMembers() {
        cout << "~WithMembers" << endl;
    }
private:
    Member Q;
    Member R;
    Member S; // Have constructors
    int i;
};

int main() {
    WithMembers WM(1);

    return 0;
} ///:~
