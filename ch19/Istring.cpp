//: C19:Istring.cpp
// Input strstreams

#include <iostream>
#include <strstream>

using namespace std;

int main() {
    istrstream s("47 1.414 This is a test");
    int i;
    float f;

    s >> i >> f; // Whitespace-delimited input

    char buf2[100];
    s >> buf2;

    cout << "i = " << i << ", f = " << f;
    cout << " buf2 = " << buf2 << endl;
    cout << s.rdbuf(); // Get the rest ...

    return 0;
} ///:~
