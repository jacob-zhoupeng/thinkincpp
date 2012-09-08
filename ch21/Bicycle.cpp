//: C21:Bicycle.cpp {0}
// Bicycle implementation
#include <algorithm>
#include <iostream>
#include <iterator>
#include <cassert>

#include "Bicycle.h"

using namespace std;

//! 静态变量定义
BicyclePart::LeakChecker BicyclePart::lc;
int Bicycle::counter = 0;

Bicycle::Bicycle() : id(counter++) {
    BicyclePart* bp[] = {
        new Part<Frame>, new Part<Wheels>,
        new Part<Seat>, new Part<HandleBar>,
        new Part<Sprockets>, new Part<Deraileur>,
    };

    const int bplen = sizeof(bp)/sizeof(*bp);
    parts = VBP(bp, bp + bplen);
}

Bicycle::Bicycle(const Bicycle& old)
        : parts(old.parts.begin(), old.parts.end()){
    for (int i = 0; i < parts.size(); i++) {
        parts[i] = parts[i]->clone();
    }
}

Bicycle& Bicycle::operator=(const Bicycle& old) {
    purge();
    parts.resize(old.parts.size());
    copy(old.parts.begin(), old.parts.end(), parts.begin());
    for (int i = 0; i < parts.size(); i++) {
        parts[i] = parts[i]->clone();
    }
    return *this;
}

Bicycle::~Bicycle() {
    purge();
}

std::ostream& operator<<(std::ostream& os, Bicycle* b) {
    copy(b->parts.begin(), b->parts.end(), 
        ostream_iterator<BicyclePart*>(os, "\n"));
    os << "----------" << endl;
    return os;
}

void Bicycle::print(vector<Bicycle*>& vb, ostream& os) {
    copy(vb.begin(), vb.end(), ostream_iterator<Bicycle*>(os, "\n"));
}

// Both the Bicycle and the
// generator should provide more variety than
// this. But I hope you get the idea.
Bicycle* BicycleGenerator::operator()() {
    return new Bicycle();
} ///:~