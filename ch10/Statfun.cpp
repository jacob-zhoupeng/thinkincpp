//: C10:Statfun.cpp
// Static vars inside functions

#include <iostream>

#include "../require.h"

using namespace std;

char onechar(const char *string = NULL) {
    static const char *s; //! 函数重入时共享同一个静态变量

    if (string != NULL) {
        s = string;
        return *s;
    } else {
        require(s, "un-initialized s");
    }

    if (*s == '\0') {
        return 0;
    }

    return *s++;
}

char *a = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"
    "~!@#$%^&*()-_=+\\|'.>?/,<{}[];:";

int main() {
    //! onechar(); // require() fails
    onechar(a); // Initializes s to a

    char c;
    while ((c = onechar()) != 0) {
        cout << c << endl;
    }

    return 0;
} ///:~
