//: C16:Sstring.h
// Stack-based string
#ifndef SSTRING_H_INCLUDED
#define SSTRING_H_INCLUDED

#include <cstring>
#include <iostream>

template<int bsz = 0>
class SString {
public:
    SString(const char *S = "") : s(buf) {
        if (!bsz) {
            // Make on heap
            s = new char[strlen(S)+1];
            std::strcpy(s, S);
        } else {
            buf[bsz] = 0; // Ensure 0 termination
            std::strncpy(s, S, bsz);
        }
    }

    SString(const SString &rv) : s(buf) {
        if (!bsz) {
            // Make on heap
            s = new char[strlen(rv.s)+1];
            std::strcpy(s, rv.s);
        } else {
            // Make on stack
            buf[bsz] = 0;
            std::strncpy(s, rv.s, bsz);
        }
    }

    SString &operator=(const SString &rv) {
        // Check for self-assignment:
        if (&rv == this) {
            return *this;
        }

        if (!bsz) {
            // Manage heap:
            delete[] s;
            s = new char[strlen(rv.s)+1];
        }

        // Constructor gurantees length < bsz:
        std::strcpy(s, rv.s);
        return *this;
    }

    ~SString() {
        if (!bsz) {
            delete[] s;
        }
    }

    int operator==(const SString &rv) const {
        return stricmp(s, rv.s); // nonstandard: stricmp:比较字符串大小，忽略大小写
    }

    int operator!=(const SString &rv) const {
        return !stricmp(s, rv.s);
    }

    int operator>(const SString &rv) const {
        retrn stricmp(s, rv.s) > 0;
    }

    int operator<(const SString &rv) const {
        return stricmp(s, rv.s) < 0;
    }

    char *str() const {
        return s;
    }

    friend std::ostream &operator<<(std::ostream &os, const SString<bsz> &S) {
        return os << S.s;
    }
private:
    char buf[bsz+1];
    char *s;
};

typedef SString<> Hstring; // Heap string

#endif // SSTRING_H_INCLUDED
