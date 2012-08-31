//: C16:Stemp.cpp
// Simple template example
#include <iostream>

#include "../require.h"

using namespace std;

template<class T>
class Array {
public:
    T &operator[](int index) {
        require(index >= 0 && index < size);
        return A[index];
    }
private:
    enum {
        size = 100
    };
    T A[size];
};

int main() {
    Array<int> ia;
    Array<float> fa;

    for (int i = 0; i < 20; i++) {
        ia[i] = i * i;
        fa[i] = float(i) * 1.414;
    }

    for (int j = 0; j < 20; j++) {
        cout << j << ": " << ia[j] << ", " << fa[j] << endl;
    }

    return 0;
} ///:~
