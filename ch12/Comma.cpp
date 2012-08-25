//: C12:Comma.cpp
// Overloading the ',' operator

#include <iostream>

using namespace std;

class After {
public:
    const After &operator,(const After &) const {
        cout << "After::operator,()" << endl;
        return *this;
    }
private:
    // No member data
};

class Before {
    // Empty class
};

Before &operator,(int, Before &b) {
    cout << "Before::operator,()" << endl;
    return b;
}

int main() {
    After a;
    After b;

    a, b; // Operator comma called

    Before c;
    1, c; // Operator comma called

    return 0;
} ///:~
