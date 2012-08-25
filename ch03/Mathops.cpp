//: C03:Mathops.cpp
// Mathematical operators

#include <iostream>

using namespace std;

// A macro to display a string and a value.
#define print(str, var) cout << str " = " << var << endl

int main() {
    int i;
    int j;
    int k;

    float u;
    float v;
    float w; // Applies to doubles, too

    cout << "enter an integer: ";
    cin >> j;
    cout << "enter another integer: ";
    cin >> k;
    print("j", j);
    print("k", k);

    i = j + k;
    print("j + k", i);
    i = j - k;
    print("j - k", i);
    i = k / j;
    print("k / j", i);
    i = k * j;
    print("k * j", i);
    i = k % j;
    print("k % j", i);

    // The flowing only works with integers:
    j %= k;
    print("j %= k", j);

    cout << "enter a floating-point number: ";
    cin >> v;
    cout << "enter a floating-point number: ";
    cin >> w;
    print("v", v);
    print("w", w);

    u = v + w;
    print("v + w", u);
    u = v - w;
    print("v - w", u);
    u = v * w;
    print("v * w", u);
    u = v / w;
    print("v / w", u);

    // The following works for ints, chars, and doubles too:
    u += v;
    print("u += v", u);
    u -= v;
    print("u -= v", u);
    u *= v;
    print("u *= v", u);
    u /= v;
    print("u /= v", u);

    return 0;
} ///:~
