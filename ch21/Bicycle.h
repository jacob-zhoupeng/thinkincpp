//: C21:Bicycle.h
// Interesting class for use with STL algorithms
#ifndef BICYCLE_H_
#define BICYCLE_H_

#include <vector>
#include <iostream>
#include <typeinfo>

class BicyclePart {
public:
    BicyclePart() {
        lc++;
    }

    virtual BicyclePart* clone() = 0;

    virtual ~BicyclePart() {
        lc--;
    }

    friend std::ostream& operator<<(std::ostream& os, BicyclePart* bp) {
        return os << typeid(*bp).name();
    }

    friend class Bicycle;
private:
    class LeakChecker {
    public:
        LeakChecker() : count(0) {}

        ~LeakChecker() {
            print();
        }

        void print() {
            std::cout << count << std::endl;
        }

        void operator++(int) {
            count++;
        }

        void operator--(int) {
            count--;
        }
    private:
        int count;
    };
    static LeakChecker lc;
};

enum BPart {
    Frame, Wheels, Seat, HandleBar,
    Sprockets, Deraileur,
};

template<BPart id>
class Part : public BicyclePart {
public:
    BicyclePart* clone() {
        return new Part<id>;
    }
};

class Bicycle {
public:
    typedef std::vector<BicyclePart*> VBP;

    Bicycle();

    Bicycle(const Bicycle& old);

    Bicycle& operator=(const Bicycle& old);

    // [Other operators as needed go here:]
    // [...]
    // [...]
    ~Bicycle();

    // So you can change parts on a bike (but be
    // careful: you must clean up any objects you
    // remove from the bicycle!)
    VBP& bikeParts() {
        return parts;
    }

    friend std::ostream& operator<<(std::ostream& os, Bicycle* b);
    static void print(std::vector<Bicycle*>& vb, std::ostream& os = std::cout);
private:
    static int counter;
    int id;
    VBP parts;

    void purge() {
        for (VBP::iterator it = parts.begin(); it != parts.end(); it++) {
            delete *it;
        }
    }
};

class BicycleGenerator {
public:
    Bicycle* operator()();
};

#endif // BICYCLE_H_ ///:~