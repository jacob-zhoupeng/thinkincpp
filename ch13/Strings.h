//: C13:Strings.h
// Simple string class
// Can only be built on the heap
#ifndef STRINGS_H_INCLUDED
#define STRINGS_H_INCLUDED

#include <cstring>
#include <iostream>

class String {
public:
    // Only make Strings on the heap:
    friend String *makeString(const char *S) {
        return new String(S);
    }
    // Alternate approach:
    static String *make(const char *S) {
        return new String(S);
    }
    ~String() {
        delete s;
    }
    //! �����Զ�����ת��
    operator char *() const {
        return s;
    }
    char *str() const {
        return s;
    }
    friend std::ostream &operator<< (std::ostream &os, const String &S) {
        return os << S.s;
    }
private:
    char *s;
    //! ˽�й��캯��
    String(const char *S) {
        s = new char[strlen(S) + 1];
        std::strcpy(s, S);
    }
    //! Prevent copying: ˽�и��ƹ��캯����˽�����ظ�ֵ�����
    String(const String &);
    void operator=(String &);
};

String *makeString(const char *S);

#endif // STRINGS_H_INCLUDED

