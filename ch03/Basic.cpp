//: C03:Basic.cpp
// Define the four basic data
// types in C & C++

#include <iostream>

using namespace std;

int main() {
    // Definition without initialization:
    char protein;
    int carbohydrates;

    float fiber;
    double fat;

    // The value is undefined also some compilers will initialize to 0
    cout << "protein = " << protein << ", carbohydrates = " << carbohydrates
        << ", fiber = " << fiber << ", fat = " << fat << endl;

    // Definition & initialization at the same time:
    char pizza = 'A';
    char pop = 'Z';

    int DongDings = 100;
    int Twinkles = 150;
    int HeeHos = 200;

    float chocolate = 3.14159;
    double fudge_ripple = 6e-4; // Exponential notation

    cout << "pizza = " << pizza << ", pop = " << pop << ", DongDings = " << DongDings
        << ", Twinkles = " << Twinkles << ", HeeHos = " << HeeHos << ", chocolate = "
        << chocolate << ", fudge_ripple = " << fudge_ripple << endl;

    return 0;
} ///:~
