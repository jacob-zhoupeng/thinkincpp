//: C15:Wind3.cpp
// Late binding with virtual

#include <iostream>

using namespace std;

enum note {
    middleC,
    Csharp,
    Cflat
}; // Etc.

class Instrument {
public:
    // virtual关键字只需要在基类成员函数的声明中
    // 即可，基类成员函数定义和子类成员函数声明
    // 和定义可以不加virtual关键字。
    virtual void play(note) const {
        cout << "Instrument::play" << endl;
    }
};

// Wind objects are Instruments
// because the have the same interface:
class Wind : public Instrument {
public:
    // Redefine interface function:
    void play(note) const {
        cout << "Wind::play" << endl;
    }
};

void tune(Instrument &i) {
    // ...
    i.play(middleC);
}

int main() {
    Wind flute;

    tune(flute); // Upcasting

    return 0;
} ///:~
