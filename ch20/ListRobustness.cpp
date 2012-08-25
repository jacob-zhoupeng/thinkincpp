//: C20:ListRobustness.cpp
// lists are harder to break

#include <list>
#include <iostream>

using namespace std;

int main() {
    list<int> li(100, 0);

    list<int>::iterator i = li.begin();

    for (int j = 0; j < li.size()/2; j++) {
        i++;
    }

    // Walk the iterator forward as you perform
    // a lot of insertions in the middle:
    for (int k = 0; k < 1000; k++) {
        li.insert(i++, 1); // No problem
    }
    
    li.erase(i); //! 这里可能已经改变了迭代器，导致迭代器非法了。
    i++;
    *i = 2; // Oops! It's invalid
    
    return 0;
} ///:~

