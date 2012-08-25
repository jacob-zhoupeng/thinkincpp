//: C19:Strmove.cpp
// ostrstream memory mevement

#include <iostream>
#include <strstream>

using namespace std;

int main() {
    ostrstream s;
    s << "hi";
    char* old = s.str(); // Freezes s
    s.rdbuf()->freeze(0); // Unfreeze

    for (int i = 0; i < 100; i++) {
        s << "howdy"; // Should force reallocation
    }
    cout << "old = " << (void*)old << endl;
    cout << "new = " << (void*)s.str(); // Freezes
    delete s.str(); // Release storage
   
    return 0;
} ///:~

