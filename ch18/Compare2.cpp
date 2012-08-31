//: C18:Compare2.cpp
// Overloaded compare()
#include <string>
#include <iostream>

using namespace std;

int main() {
    string first("This");
    string second("That");

    // Compare first two characters of each string:
    switch (first.compare(0, 2, second, 0, 2)) {
    case 0: // The same
        cout << first << " and " << second
             << " are lexically equal" << endl;
        break;
    case -1: // Less than
        first.swap(second);
        // Fall through this case ...
    case 1: // Greater than
        cout << first << " is lexically greater that "
             << second << endl;
    }

    return 0;
} ///:~
