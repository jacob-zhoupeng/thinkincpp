//: C21:PrintSequence.h
// Prints the contents of any sequence

#ifndef PRINTSEQUENCT_H_
#define PRINTSEQUENCT_H_

#include <iostream>
#include <iterator>

template<typename T, typename InputIter>
void print(InputIter first, InputIter last, char* nm = "", char* sep = "\n",
        std::ostream& os = std::cout) {
    if (*nm != '\0') { // Only if you provide a string
        os << nm << ": " << sep; // is this printed
    }

    std::copy(first, last, std::ostream_iterator<T>(os, sep));
    os << std::endl;
}

template<typename T, typename Cont>
void print(Cont& c, char* nm = "", char* sep = "\n", 
        std::ostream& os = std::cout) {
    if (*nm != '\0') { // Only if you provide a string
        os << nm << ": " << sep; // is this pinted
    }
    std::copy(c.begin(), c.end(), std::ostream_iterator<T>(os, sep));
    os << std::endl;
}

#endif // PRINTSEQUENCT_H_ ///:~