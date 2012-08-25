//: C15:Wind2.cpp
// Inheritance & upcasting

#include <iostream>

using namespace std;

enum note {
    middileC, Csharp, Cflat
}; // Etc.

class Instrument {
public:
    void play(note) const {
        cout << "Instrument::play" << endl;
    }
};

// Wind objects are Instruments
// because they have the same interface:
class Wind : public Instrument {
public:
    // Reference interface function:
    void play(note) const {
        cout << "Wind::play" << endl;
    }
};

void tune(Instrument &i) {
    // ...
    i.play(middileC);
}

int main() {
    Wind flute;

    tune(flute); // Upcasting

    return 0;
} ///:~
