//: C08:SStack.cpp
// enum inside classes

#include <cstring>
#include <iostream>

using namespace std;

class StringStack {
public:
    StringStack();
    void push(const char *s);
    const char *pop();
private:
    //! 枚举类型可以作为类内部const常量
    enum {
        size = 100
    };
    const char *Stack[size];
    int index;
};

//! C++初始化新语法
StringStack::StringStack() : index(0) {
    memset(Stack, 0, size * sizeof(char *));
}

void StringStack::push(const char *s) {
    if (index < size) {
        Stack[index++] = s;
    }
}

const char *StringStack::pop() {
    if (index > 0) {
        const char *rv = Stack[--index];
        Stack[index] = NULL;

        return rv;
    }

    return NULL; //! Add to compete the if syntax
}

const char *iceCream[] = {
    "parlines & cream",
    "fudge ripple",
    "jamocha almond fudge",
    "wild mountain blackberry",
    "raspberry sorbet",
    "lemon swirl",
    "rocky road",
    "deep chocolate fudge"
};

//! const ICsz = sizeof(iceCream) / sizeof(*iceCream); // 原书代码可能有误
const int ICsz = sizeof(iceCream) / sizeof(*iceCream);

int main() {
    StringStack SS;

    for (int i = 0; i < ICsz; i++) {
        SS.push(iceCream[i]);
    }

    const char *cp;
    while ((cp = SS.pop()) != NULL) {
        cout << cp << endl;
    }

    return 0;
} ///:~
