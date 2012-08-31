//: C03:Readword.cpp
// Read and echo a word from standard input
#include <iostream>

using namespace std;

int main() {
    char buf[100];

    cout << "type a word: ";
    cin >> buf;
    cout << "the word you typed is: " << buf << endl;

    return 0;
} ///:~
