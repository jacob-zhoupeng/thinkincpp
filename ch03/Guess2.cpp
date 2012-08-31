//: C03:Guess2.cpp
// The guess program using do-while
#include <iostream>

using namespace std;

int main() {
    int secret = 15;
    int guess; // No initialization needed this time
    do {
        cout << "guess the number: ";
        cin >> guess;
    } while (guess != secret);
    cout << "you got it!" << endl;

    return 0;
} ///:~
