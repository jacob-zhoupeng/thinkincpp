//: C16:Stemp2.cpp
// Non-inline template example
#include "require.h"

template<class T>
class Array {
public:
    T &operator[](int index);
private:
    enum {
        size = 100
    };
    T A[size];
};

template<class T>
T &Array<T>::operator[](int index) {
    require(index >= 0 && index < size, "Index out of range");
    return A[index];
}

int main() {
    Array<float> fa;

    fa[0] = 1.414;
} ///:~
