//: C20:VectorOfBool.cpp
// Demonstrate the vector<bool> specialization

#include <iostream>
#include <sstream>
#include <vector>
#include <bitset>
#include <iterator>

using namespace std;

int main(int argc, char* argv[]) {
    vector<bool> vb(10, true);
    vector<bool>::iterator it;

    for (it = vb.begin(); it != vb.end(); it++) {
        cout << *it;    
    }
    cout << endl;

    vb.push_back(false);
    ostream_iterator<bool> out(cout, "");
    copy(vb.begin(), vb.end(), out);
    cout << endl;
    bool ab[] = { true, false, false, true, true, true, true, 
        false, false, true };

    // There's a similar constructor:
    vb.assign(ab, ab + sizeof(ab)/sizeof(bool));
    copy(vb.begin(), vb.end(), out);
    cout << endl;

    vb.flip(); // Flip all bits

    copy(vb.begin(), vb.end(), out);
    cout << endl;

    for (int i = 0; i < vb.size(); i++) {
        vb[i] = 0; // (Equivalent to "false")
    }

    vb[4] = true;
    vb[5] = 1;
    vb[7].flip(); // Invert one bit
    copy(vb.begin(), vb.end(), out);
    cout << endl;

    // Convert to a bitset:
    ostringstream os;
    copy(vb.begin(), vb.end(), ostream_iterator<bool>(os, ""));
    bitset<10> bs(os.str());
    cout << "Bitset:\n" << bs << endl;
    
    return 0;
} ///:~
