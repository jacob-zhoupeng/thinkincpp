//: C20:StreambufIterator.cpp
// istreambuf_iterator & ostreambuf_iterator

#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>

#include "../require.h"

using namespace std;

int main() {
    ifstream in("StreambufIterator.cpp");
    require(in, "StreambufIterator.cpp");

    // Exact representation of stream:
    istreambuf_iterator<char> isb(in);
    istreambuf_iterator<char> end;

    ostreambuf_iterator<char> osb(cout);

    while (isb != end) {
        *osb++ = *isb++; // Copy 'in' to cout
    }
    cout << endl;

    ifstream in2("SterambufIterator.cpp");
    // Strips white space:
    istream_iterator<char> is(in2);
    istream_iterator<char> end2;
    ostream_iterator<char> os(cout);

    while (is != end2) {
        *os++ = *is++;
    }
    cout << endl;

    return 0;
} ///:~

