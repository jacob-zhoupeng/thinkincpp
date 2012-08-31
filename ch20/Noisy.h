//: C20:Noisy.h
// A class to track various object activities
#ifndef NOISY_H
#define NOISY_H

#include <iostream>

class Noisy {
public:
    Noisy() : id(create++) {
        std::cout << "d[" << id << "]";
    }

    Noisy(const Noisy& rv) : id(rv.id) {
        std::cout << "c[" << id << "]";
        copycons++;
    }

    Noisy& operator=(const Noisy& rv) {
        std::cout << "(" << id << ")=[" <<
            rv.id << "]";
        id = rv.id;
        assign++;

        return *this;
    }

    ~Noisy() {
        std::cout << "~[" << id << "]";
        destroy++;
    }

    friend std::ostream& operator<<(std::ostream& os, const Noisy& n) {
        return os << n.id;
    }

    friend bool operator<(const Noisy& lv, const Noisy& rv) {
        return lv.id < rv.id;
    }

    friend bool operator==(const Noisy& lv, const Noisy& rv) {
        return lv.id == rv.id;
    }

    friend class NoisyReport;
private:
    static long create;
    static long assign;
    static long copycons;
    static long destroy;
    long id;
};

struct NoisyGen {
    Noisy operator()() {
        return Noisy();
    }
};

// A singleton. Will automatically report the
// statistics as the program terminates:
class NoisyReport {
public:
    ~NoisyReport() {
        std::cout << "\n-------------------\n"
            << "Noisy creations: " << Noisy::create
            << "\nCopy-Constructions: " << Noisy::copycons
            << "\nAssignments: " << Noisy::assign
            << "\nDestructions:" << Noisy::destroy
            << std::endl;
    }
private:
    static NoisyReport nr;
    NoisyReport() {} // Private constructor
};

//! 静态成员变量定义
// Because of these this file can only be used
// in simple test situations. Move them to a
// .cpp file or more complex programs:
long Noisy::create = 0;
long Noisy::assign = 0;
long Noisy::copycons = 0;
long Noisy::destroy = 0;

NoisyReport NoisyReport::nr;

#endif // NOISY_H

