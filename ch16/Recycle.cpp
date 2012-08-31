//: C16:Recycle.cpp
// Containers & polymorphism
#include <fstream>
#include <cstdlib>
#include <ctime>

#include "TStack.h"

using namespace std;

ofstream out("recycle.out");

enum TrashType {
    AluminumT, PaperT, GlassT
};

class Trash {
public:
    Trash(float Wt) : Weight(Wt) {
        // Empty body
    }

    virtual TrashType trashType() const = 0;
    virtual const char *name() const = 0;
    virtual float value() const = 0;

    float weight() const {
        return Weight;
    }

    virtual ~Trash() {
        // Empty body
    }
private:
    float Weight;
};

class Aluminum : public Trash {
public:
    Aluminum(float Wt) : Trash(Wt) {
        // Empty body
    }

    TrashType trashType() const {
        return AluminumT;
    }

    const char *name() const {
        return "Aluminum";
    }

    float value() const {
        return val;
    }

    static void value(int newval) {
        val = newval;
    }
private:
    static float val;
};

float Aluminum::val = 1.67;

class Paper : public Trash {
public:
    Paper(float Wt) : Trash(Wt) {
        // Empty body
    }

    TrashType trashType() const {
        return PaperT;
    }

    const char *name() const {
        return "Paper";
    }

    float value() const {
        return val;
    }

    static void value(int newval) {
        val = newval;
    }
private:
    static float val;
};

float Paper::val = 1.10;

class Glass : public Trash {
public:
    Glass(float Wt) : Trash(Wt) {
        // Empty body
    }

    TrashType trashType() const {
        return GlassT;
    }

    const char *name() const {
        return "Glass";
    }

    float value() const {
        return val;
    }

    static void value(int newval) {
        val = newval;
    }
private:
    static float val;
};

float Glass::val = 0.23;

// Sum up the value of the Trash in a bin:
void SumValue(const TStack<Trash> &bin, ostream &os) {
    TStackIterator<Trash> tally(bin);
    float val = 0;

    while (tally != NULL) {
        val += tally->weight() * tally->value();
        os << "weight of " << tally->name() << " = "
        << tally->weight() << endl;
        tally++;
    }

    os << "Total value = " << val << endl;
}

int main() {
    srand(time(NULL)); // Seed random number generator
    TStack<Trash> bin; // Default to ownership
    // Fill up the Trash bin:
    for (int i = 0; i < 30; i++) {
        switch (rand() % 3) {
        case 0:
            bin.push(new Aluminum(rand() % 100));
            break;
        case 1:
            bin.push(new Paper(rand() % 100));
            break;
        case 2:
            bin.push(new Glass(rand() % 100));
            break;
        }

        // Bins to sort into:
        TStack<Trash> glassBin(0); // No ownership
        TStack<Trash> paperBin(0);
        TStack<Trash> alBin(0);
        TStackIterator<Trash> sorter(bin);

        // Sort the Trash:
        // (RTTI offers a nicer solution)
        while (sorter) {
            // Smart pointer call:
            switch(sorter->trashType()) {
            case AluminumT:
                alBin.push(sorter.current());
                break;
            case PaperT:
                paperBin.push(sorter.current());
                break;
            case GlassT:
                glassBin.push(sorter.current());
                break;
            }

            sorter++;
        }

        SumValue(alBin, out);
        SumValue(paperBin, out);
        SumValue(glassBin, out);
        SumValue(bin, out);

        return 0;
    }
} ///:~
