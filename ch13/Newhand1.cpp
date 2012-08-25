//: C13:Newhand1.cpp
// Changing the new-handler

#include <iostream>
#include <cstdlib>
#include <new>

using namespace std;

// The new-handler function must take no arguments and have
// void return value.
void out_of_memory() {
    cerr << "memory exhausted!" << endl;
    exit(1);
}

int main() {
    //! 设置new关键字失败时调用的处理函数
    set_new_handler(out_of_memory);
    while (true) {
        new int[1000]; // Exhausts memory
    }

    return 0;
} ///:~
