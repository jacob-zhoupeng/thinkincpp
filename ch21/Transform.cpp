//: C21:Transform.cpp
// Use of STL transform() algorithm
#include <iostream>
#include <algorithm>
#include <vector>

#include "Counted.h"

using namespace std;

template<class T>
T* deleteP(T* x) {
    delete x;
    return 0;
}

template<class T>
struct Deleter {
    T* operator()(T* x) {
        delete x;
        return 0;
    }
};

int main(int argc, char* argv[]) {
    CountedVector cv("one");
    transform(cv.begin(), cv.end(), cv.begin(), deleteP<Counted>);

    CountedVector cv2("two");
    transform(cv2.begin(), cv2.end(), cv2.begin(), Deleter<Counted>());

    return 0;
} ///:~