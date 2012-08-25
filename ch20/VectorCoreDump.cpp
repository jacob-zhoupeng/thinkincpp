//: C20:VectorCoreDump.cpp
// How to break a program using a vector

#include <vector>
#include <iostream>
#include <iterator>

using namespace std;

int main() {
    vector<int> vi(10, 0);

    ostream_iterator<int> out(cout, " ");
    copy(vi.begin(), vi.end(), out);

    vector<int>::iterator i = vi.begin();
    cout << "\n i: " << long(i) << endl;
    *i = 47;
    copy(vi.begin(), vi.end(), out);

    // Force it to move memory (coule also just add
    // enough objects):
    vi.resize(vi.capacity() + 1);

    // Now i points to wrong memory:
    cout << "\n i: " << long(i) << endl;
    cout << "vi.begin(): " << long(vi.begin());
    *i = 48; // Access violation

    return 0;
} ///:~

