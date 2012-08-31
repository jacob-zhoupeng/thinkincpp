//: C12:Strings1.cpp
// No auto type conversion

#include <cstdio>
#include <cstring>
#include <cstdlib>

#include "../require.h"

using namespace std;

class Stringc {
public:
    Stringc(const char *S = "") {
        s = (char *) malloc(strlen(S) + 1);
        require(s != NULL);
        strcpy(s, S);
    }
    ~Stringc() {
        free(s);
    }
    int Strcmp(const Stringc &S) const {
        return ::strcmp(s, S.s); //! 调用string.h头文件中的strcmp()函数
    }
    // ... etc., for every function in string.h
private:
    char *s;
};

int main() {
    Stringc s1("hello");
    Stringc s2("there");

    printf("s1 compares to s2: %d", s1.Strcmp(s2));
} ///:~
