//: C18:ichar_traits.h
// Creating your own character traits
#ifndef ICHAR_TRAITS_H_INCLUDED
#define ICHAR_TRAITS_H_INCLUDED

#include <string>

struct ichar_traits : std::char_traits<char> {
    // We'll only change character by
    // character comparison functions
    static bool eq(char clst, char c2nd) {
        return toupper(clst) == toupper(c2nd);
    }

    static bool ne(char c1st, char c2nd) {
        return toupper(c1st) != toupper(c2nd);
    }

    static bool lt(char c1st, char c2nd) {
        return toupper(c1st) < toupper(c2nd);
    }

    static int compare(const char* str1, const char* str2,
                       size_t n) {
        for (unsigned int i = 0; i < n; i++) {
            if (tolower(*str1) > tolower(*str2)) {
                return 1;
            }
            if (tolower(*str1) < tolower(*str2)) {
                return -1;
            }
            if (*str1 == 0 || *str2 == 0) {
                return 0;
            }
        }
        return 0;
    }

    static const char* find(const char* s1, int n, char c) {
        while (n-- > 0 && toupper(*s1) != toupper(c)) {
            s1++;
        }
        return s1;
    }
};

#endif // ICHAR_TRAITS_H_INCLUDED
