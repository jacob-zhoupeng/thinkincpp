//: C18:StringIterators.cpp

#include <string>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    string source("xxxx");
    string s(source.begin(), source.end());

    cout << s << endl;

    return 0;
} ///:~
