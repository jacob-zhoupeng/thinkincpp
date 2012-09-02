//: C21:NString.h
// A "numbered string" that indicates which
// occurrence this is of a particular word

#ifndef NSTRING_H_
#define NSTRING_H_

#include <string>
#include <map>
#include <iostream>

class NString {
public:
    NString() : occurrence(0) {}
    
    //! 添加构造函数，使Manipulations.cpp编译通过 by <jacob.zhoupeng@gmail.com>
    NString(char* str) : s(str), occurrence(occurMap[s]++) {}

    NString(const std::string& x) : s(x), occurrence(occurMap[s]++) {}

    // The synthesized operator= and
    // copy-constructor are OK here

    friend std::ostream& operator<<(std::ostream& os, const NString& ns) {
        return os << ns.s << " [" << ns.occurrence << "]";
    }

    // Need this for sorting. Notice it noly
    // compares strings, not occurrences:
    friend bool operator<(const NString& lValue, const NString& rValue) {
        return lValue.s < rValue.s;
    }

    // For sorting with greater<NString>:
    friend bool operator>(const NString& lValue, const NString& rValue) {
        return lValue.s > rValue.s;
    }

    // To get at the string directly:
    operator const std::string&() const {
        return s;
    }
private:
    std::string s;
    int occurrence;

    struct Counter {
        Counter() : i(0) {}
        Counter& operator++(int) {
            i++;
            return *this;
        } // Post-incr
        operator int() {
            return i;
        }
        int i;
    };

    // Keep track of the number of occurrences:
    typedef std::map<std::string, Counter> csmap;
    static csmap occurMap;
};

//! Allocate static number object. Done here for
//! brevity, but should actually be done in a
//! separate CPP file:
NString::csmap NString::occurMap;

#endif // NSTRING_H_ ///:~