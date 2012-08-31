//: C03:Guess.cpp
// Guess a number (demonstrates "while")
#include <iostream>

using namespace std;

int main() {
    int secret = 15;
    int guess = 0;
    // "!=" is the "not-equal" conditional:
    while (guess != secret) { // Compound statement
        cout << "guss the number: ";
        cin >> guess;
    }
    cout << "You got it!" << endl;

    return 0;
} ///:~
