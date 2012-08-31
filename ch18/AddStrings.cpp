//: C18:AddStrings.cpp
#include <string>
#include <iostream>

using namespace std;

int main() {
    string s1("This ");
    string s2("That ");
    string s3("The other ");

    // operator+ concatenates strings
    s1 = s1 + s2;
    cout << s1 << endl;

    // Another way to concatenates strings
    s1 += s3;
    cout << s1 << endl;

    // You can index the string on the right
    s1 += s3 + s3[4] + "oh lala";
    cout << s1 << endl;

    return 0;
} ///:~
