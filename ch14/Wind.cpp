//: C14:Wind.cpp
// Inheritance & upcasting

enum note {
    middleC, Csharp, Cflat
}; // Etc.

class Instrument {
public:
    void play(note) const {
        // Empty body
    }
};

// Wind objects are Instruments
// because they have the same interface:
class Wind : public Instrument {
    // Empty class body
};

void tune(Instrument &i) {
    // ...
    i.play(middleC);
}

int main() {
    Wind flute;

    tune(flute);

    return 0;
} ///:~
