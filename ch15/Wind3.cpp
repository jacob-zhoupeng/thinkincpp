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
    // virtual�ؼ���ֻ��Ҫ�ڻ����Ա������������
    // ���ɣ������Ա��������������Ա��������
    // �Ͷ�����Բ���virtual�ؼ��֡�
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
