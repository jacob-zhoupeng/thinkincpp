//: C12:Strings2.cpp
// With auto type conversion

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
    operator const char *() const {
        return s;
    }
private:
    char *s;
};

int main() {
    Stringc s1("hello");
    Stringc s2("there");

    strcmp(s1, s2); // Standard C function
    strspn(s1, s2); // Any string function!

    return 0;
} ///:~
