//: C18:BadStringIndexing.cpp
#include<string>
#include<iostream>

using namespace std;

int main() {
    string s("1234");

    // Run-time problem: goes beyond array bounds:
    cout << s[5] << endl;

    // Saves you by throwing an exception:
    cout << s.at(5) << endl;

    return 0;
} ///:~
