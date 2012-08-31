//: C18:ICompare.cpp
#include <string>
#include <iostream>
#include "ichar_traits.h"

using namespace std;

typedef basic_string<char, ichar_traits, allocator<char> > istring;

int main() {
    // The same letters except for case:
    istring first = "tHis";
    istring second = "ThIS";

    cout << first.compare(second) << endl;

    return 0;
} ///:~
