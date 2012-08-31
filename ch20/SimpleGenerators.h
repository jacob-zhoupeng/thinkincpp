//: C20:SimpleGenerators.h
// Generic generators, including one that
// creates pairs
#include <iostream>
#include <utility>

// A generator that increments its value:
template<typename T>
class IncrGen {
public:
    IncrGen(T ii) : i(ii) {}

    T operator()() {
        return i++;
    }
private:
    T i;
};

// A generator that produces a STL pair<>:
template<typename T1, typename T2>
class PairGen {
public:
    PairGen(T1 ii, T2 jj) : i(ii), j(jj) {}

    std::pair<T1, T2> operator()() {
        return std::pair<T1, T2>(i++, j++);
    }
private:
    T1 i;
    T2 j;
};

// A generic global operator<< for printing any STL pair<>:
template<typename Pair>
std::ostream& operator<<(std::ostream& os, Pair& p) {
    return os << p.first << "\t" << p.second << std::endl;
} ///:~
