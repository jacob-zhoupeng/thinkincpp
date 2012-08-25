//: C09:Inline.cpp
// Inlines inside classes

#include <iostream>

using namespace std;

class Point {
public:
    Point() {
        i = j = k = 0;
    }
    Point(int I, int J, int K) {
        i = I;
        j = J;
        k = K;
    }
    // 定义在类内部的函数自动为inline函数
    void print(const char *msg = "") const {
        if (*msg != '\0') {
            cout << msg << endl;
        }
        cout << "i = " << i << ", "
            << "j = " << j << ", "
            << "k = " << k << endl;
    }
private:
    int i;
    int j;
    int k;
};

int main() {
    Point p;
    Point q(1, 2, 3);

    p.print("value of p");
    q.print("value of q");

    return 0;
} ///:~
