//: C03:Getline.cpp
// Stream input by lines
#include <iostream>

using namespace std;

int main() {
    char buf[100];
    char trash;

    while (cin.get(buf, 100)) { // Get chars until '\n'
        cin.get(trash); // Throw away the terminator
        cout << buf << "\n"; // Add the '\n' at the end
    }

    return 0;
} ///:~
