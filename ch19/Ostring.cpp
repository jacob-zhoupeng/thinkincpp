//: C19:Ostring.cpp
// Output strstreams

#include <iostream>
#include <strstream>

using namespace std;

#define SZ (100)

int main() {
    cout << "type an int, a float and a string:";
    int i;
    float f;
    cin >> i >> f;
    cin >> ws; // Throw away white space
    char buf[SZ];
    cin.getline(buf, SZ); // Get rest of the line
    // (cin.rdbuf() would be awkward)
    ostrstream os(buf, SZ, ios::app);

    os << endl;
    os << "integer = " << i << endl;
    os << "float = " << f << endl;
    os << ends;

    cout << buf;
    cout << os.rdbuf(); // Same effect
    cout << os.rdbuf(); // NOT the same effect

    return 0;
} ///:~
