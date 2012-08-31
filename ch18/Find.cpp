//: C18:Find.cpp
// Find a group of characters in a string
#include <string>
#include <iostream>

using namespace std;

int main() {
    string chooseOne("Eenie, meenie, miney, mo");
    unsigned int i = chooseOne.find("een");
    while (i != string::npos) {
        cout << i << endl;
        i++;
        i = chooseOne.find("een", i);
    }

    return 0;
} ///:~
