//: C03:Ifthen.cpp
// Demonstration of if and if-else conditionals
#include <iostream>

using namespace std;

int main() {
    int i;
    cout << "type a number and a carriage return" << endl;
    cin >> i;
    if ( i > 5) {
        cout << "the number was greater than 5 " << endl;
    } else {
        if (i < 5) {
            cout << "the number was less than 5 " << endl;
        } else {
            cout << "the number must be equal to 5 " << endl;
        }
    }

    cout << "type a number and a carriage return" << endl;
    cin >> i;
    if (i < 10) {
        if (i > 5) { // "if" is just another type of statement
            cout << " 5 < i < 10" << endl;
        } else {
            cout << "i <= 5 " << endl;
        }
    } else { // Mathes "if (i < 10)"
        cout << "i >= 10 " << endl;
    }

    return 0;
} ///:~
