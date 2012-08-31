//: C20:assoGen.h
// The fill_n() and generate_n() equivalents
// for associative containers.
#ifndef ASSOCGEN_H_
#define ASSOCGEN_H_

template<class Assoc, class Count, class T>
void assocFill_n(Assoc& a, Count n, const T& val) {
    for (; 0 < n; --n) {
        a.insert(val);
    }
}

template<class Assoc, class Count, class Gen>
void assocGen_n(Assoc& a, Count n, Gen g) {
    for (; 0 < n; --n) {
        a.insert(g());
    }
}

#endif // ASSOCGEN_H_ ///:~
