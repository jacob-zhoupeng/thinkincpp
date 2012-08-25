//: C19:Walrus.cpp
// Freezing a strstream

#include <iostream>
#include <strstream>

using namespace std;

int main() {
    ostrstream s;
    s << "'The time has come', the walrus said,";
    s << ends;
    cout << s.str() << endl; // String is frozen
    // s is frozen; destructor won't delete
    // the streambuf storage on the heap
    s.seekp(-1, ios::cur); // Back up before NULL
    s.rdbuf()->freeze(0); // Unfreeze it
    // Now destructor releases momory, and
    // you can add more characters (but you
    // better not use the previous str() value)
    s << " 'To speak of many things'" << endl;
    cout << s.rdbuf();

    return 0;
} ///:~
