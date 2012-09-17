//: C24:Recycle2.cpp
// Chapter 14 example w/ RTTI
#include <fstream>
#include <vector>
#include <typeinfo>
#include <cstdlib>
#include <ctime>

#include "../purge.h"

using namespace std;

ofstream out("recycle2.out");

class Trash {
public:
    Trash(float Wt) : Weight(Wt) {}

    virtual float value() const = 0;

    float weight() const {
        return Weight;
    }

    virtual ~Trash() {
        out << "~Trash()\n";
    }
private:
    float Weight;
};

class Aluminum : public Trash {
public:
    Aluminum(float Wt) : Trash(Wt) {}

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
    Paper(float Wt) : Trash(Wt) {}

    float value() const {
        return val;
    }

    static void value(int newval) {
        val = newval;
    }
private:
    static float val;
};

float Paper::val = 0.10;

class Glass : public Trash {
public:
    Glass(float Wt) : Trash(Wt) {}

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

// Sums up the value of the Trash in  a bin:
template<class Container>
void SumValue(Container& bin, ostream& os) {
    typename Container::iterator tally = bin.begin();
    float val = 0;

    while (tally != bin.end()) {
        val += (*tally)->weight() * (*tally)->value();
        os << "weight of " 
            << typeid(*tally).name() 
            << " = " << (*tally)->weight() << endl;
        tally++;
    }

    os << "Total value = " << val << endl;
}

int main(int argc, char* argv[]) {
    srand(time(0)); // Seed random number generator
    vector<Trash*> bin;

    // Fill up the Trash bin:
    for (int i = 0; i < 30; i++) {
        switch(rand() % 3) {
            case 0:
                bin.push_back(new Aluminum(rand() % 100));
                break;
            case 1:
                bin.push_back(new Paper(rand() % 100));
                break;
            case 2:
                bin.push_back(new Glass(rand() % 100));
                break;
            default: // No possibility to get here
                break;
        }
    }

    // Note difference w/ chapter 14: Bins hold
    // exact type of object, not base type:
    vector<Glass*> glassBin;
    vector<Paper*> paperBin;
    vector<Aluminum*> alBin;
    
    vector<Trash*>::iterator sorter = bin.begin();

    // Sort the Trash:
    while (sorter != bin.end()) {
        Aluminum* ap = dynamic_cast<Aluminum*>(*sorter);
        Paper* pp = dynamic_cast<Paper*>(*sorter);
        Glass* gp = dynamic_cast<Glass*>(*sorter);

        if (ap) {
            alBin.push_back(ap);
        }

        if (pp) {
            paperBin.push_back(pp);
        }

        if (gp) {
            glassBin.push_back(gp);
        }

        sorter++;
    }

    SumValue(alBin, out);
    SumValue(paperBin, out);
    SumValue(glassBin, out);
    SumValue(bin, out);

    purge(bin);

    return 0;
} ///:~