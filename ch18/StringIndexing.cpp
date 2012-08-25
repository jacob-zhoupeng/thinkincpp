//: C18:StringIndexing.cpp

#include <string>
#include <iostream>

using namespace std;

int main() {
    string s("1234");

    cout << s[1] << " ";
    cout << s.at(1) << endl;

    return 0;
} ///:~
