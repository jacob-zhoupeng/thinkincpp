//: C11:Refptr.cpp
// Reference to pointer

#include <iostream>

using namespace std;

//! 等价于指向指针的指针
void increment(int *&i) {
    i++;
}

int main() {
    int *i = NULL;

    cout << "i = " << i << endl;
    increment(i);
    cout << "i = " << i << endl;

    return 0;
} ///:~
