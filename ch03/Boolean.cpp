//: C03:Boolean.cpp
// Relational and logical operators.

#include <iostream>

using namespace std;

int main() {
    int i;
    int j;

    cout << "enter an integer: ";
    cin >> i;
    cout << "enter another integer: ";
    cin >> j;

    cout << "i > j is " << (i > j) << endl;
    cout << "i < j is " << (i < j) << endl;
    cout << "i >= j is " << (i >= j) << endl;
    cout << "i <= j is " << (i <= j) << endl;
    cout << "i == j is " << (i == j) << endl;
    cout << "i != j is " << (i != j) << endl;

    cout << "i && j is " << (i && j) << endl;
    cout << "i || j is " << (i || j) << endl;
    cout << "(i < 10) && (j < 10) is " << ((i < 10) && (j < 10)) << endl;

    return 0;
} ///:~
