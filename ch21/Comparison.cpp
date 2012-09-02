//: C21:Comparison.cpp
// The STL range comparison algorithms

#include <vector>
#include <algorithm>
#include <functional>
#include <string>

#include "PrintSequence.h"

using namespace std;

int main(int argc, char* argv[]) {
    // strings provide a convenient way to create
    // ranges of characters, but you should normally
    // look for native string operations:
    string s1("This is a test");
    string s2("This is a Test");

    cout << "s1: " << s1 << endl << "s2: " << s2 << endl;
    cout << "compare s1 & s1: "  
        << equal(s1.begin(), s1.end(), s1.begin()) << endl;
    cout << "compare s1 & s2: "
        << equal(s1.begin(), s1.end(), s2.begin()) << endl;

    cout << "lexicographical_compare s1 & s1: " 
        << lexicographical_compare(s1.begin(), s1.end(), s1.begin(), s1.end()) 
        << endl;
    cout << "lexicographical_compare s1 & s2: "
        << lexicographical_compare(s1.begin(), s1.end(), s2.begin(), s2.begin())
        << endl;

    cout << "lexicographical_compare shortened "
        "s1 & full-length s2: " << endl;
    string s3(s1);

    while (s3.length() != 0) {
        bool result = lexicographical_compare(s3.begin(), s3.end(), 
            s2.begin(), s2.end());
        cout << s3 << endl << s2 << ", result = " << result << endl;
        if (result == true) {
            break;
        }
        s3 = s3.substr(0, s3.length() - 1);
    }

    pair<string::iterator, string::iterator> p = 
        mismatch(s1.begin(), s1.end(), s2.begin());
    print<char>(p.first, s1.end(), "p.first", "");
    print<char>(p.second, s2.end(), "p.second", "");

    return 0;
} ///:~