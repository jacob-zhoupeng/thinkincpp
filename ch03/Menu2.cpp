//: C03:Menu2.cpp
// A menu using a switch statement
#include <iostream>

using namespace std;

int main() {
    char response; // The user's response
    int quit = 0; // Flag for quitting

    while (quit == 0) {
        cout << "Select a, b, c or q to quit: ";
        cin >> response;
        switch (response) {
            case 'a':
                cout << "you chose 'a'" << endl;
                break;
            case 'b':
                cout << "you chose 'b'" << endl;
                break;
            case 'c':
                cout << "you chose 'c'" << endl;
                break;
            case 'q':
                cout << "quitting menu" << endl;
                quit = 1; // Sets quit flag
                break;
            default:
                cout << "Please use a, b, c or q!" << endl;
        }
    }

    return 0;
} ///:~
