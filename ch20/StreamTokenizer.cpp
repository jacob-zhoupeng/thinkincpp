//: C20:StreamTokenizer.cpp {0}

#include "StreamTokenizer.h"

using namespace std;

string StreamTokenizer::next() {
    string result;

    if (p != end) {
        insert_iterator<string> ii(result, result.begin());

        // Find the first character that isn't the delimiter
        while (isDelimiter(*p) && p != end) {
            p++;
        }

        // Count a word
        while (!isDelimiter(*p) && p != end) {
            *ii++ = *p++;
        }
    }

    return result;
} ///:~

