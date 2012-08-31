//: C20:TokenIterator.h
#ifndef TOKENITERATOR_H_
#define TOKENITERATOR_H_

#include <string>
#include <iterator>
#include <algorithm>
#include <cctype>

struct Isalpha {
    bool operator()(char c) {
        return isalpha(c);
    }
};

class Delimiters {
public:
    Delimiters() {}

    Delimiters(const std::string& excl) : exclude(excl) {}

    bool operator()(char c) {
        return exclude.find(c) == std::string::npos;
    }
private:
    std::string exclude;
};

template<class InputIter, class Pred = Isalpha>
class TokenIterator : public std::iterator<std::input_iterator_tag, 
        std::string, ptrdiff_t> {
public:
    TokenIterator(InputIter begin, InputIter end, Pred pred = Pred())
            : first(begin), last(end), predicate(pred) {
       ++*this; 
    }

    TokenIterator() {} // End sentinel

    // Prefix increment:
    TokenIterator& operator++() {
        word.resize(0); //! erase the current value of  word
        first = std::find_if(first, last, predicate);

        while (first != last && predicate(*first)) {
            word += *first++;
        }

        return *this;
    }

    // Postfix increment
    class Proxy {
    public:
        Proxy(const std::string& w) : word(w) {}

        std::string operator*() {
            return word;
        }
    private:
        std::string word;
    };

    Proxy operator++(int) {
        Proxy d(word);
        ++*this;
        return d;
    }

    // Produce the actual value:
    std::string operator*() const {
        return word;
    }

    std::string* operator->() const {
        return &(operator*());
    }

    // Compare iterators:
    bool operator==(const TokenIterator&) {
        return word.size() == 0 && first == last;
    }

    bool operator!=(const TokenIterator& rv) {
        return !(*this == rv);
    }
private:
    InputIter first;
    InputIter last;
    std::string word;
    Pred predicate;
}

#endif // TOKENITERATOR_H_

