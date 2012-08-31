//: C20:Ring.cpp
// Making a "Ring" data structure from the STL

#include <iostream>
#include <iterator>
#include <list>
#include <string>

using namespace std;

template<class T>
class Ring {
public:
    // Declaration necessary so the following
    // 'friend' statement sees this 'iterator'
    // instead of std::iterator:
    class iterator;
    friend class iterator;
    
    class iterator: public std::iterator<std::bidirectional_iterator_tag, T, ptrdiff_t> {
    public:
        // "typename" necessory to resolve nesting:
        iterator(list<T>& lst, const typename list<T>::iterator& i) 
            : r(&lst), it(i) {}
    
        bool operator==(const iterator& x) const {
            return it = x.it;
        }
    
        bool operator!=(const iterator& x) const {
            return !(*this == x);
        }
    
        list<T>::reference operator*() const {
            return *it;
        }
    
        iterator& operator++() {
            ++it;
            if (it == r->end()) {
                it = r->begin();
            }
            return *this;
        }
    
        iterator operator++(int) {
            iterator tmp = *this;
            ++*this;
            return tmp;
        }
    
        iterator& operator--() {
            if (it == r->begin()) {
                it = r->end();
            }
            --it;
            return *this;
        }
    
        iterator operator--(int) {
            iterator tmp = *this;
            --*this;
            return tmp;
        }
    
        iterator insert(const T& x) {
            return iterator(*r, r->insert(it, x));
        }
    
        iterator erase() {
            return iterator(*r, r->erase(it));
        }
    private:
        list<T>::iterator it;
        list<T>* r;
    };

    void push_back(const T& x) {
        lst.push_back(x);
    }

    iterator begin() {
        return iterator(lst, lst.begin());
    }

    int size() {
        return list.size();
    }
private:
    list<T> lst;
};


int main(int argc, char* argv[]) {
    Ring<string> rs;

    rs.push_back("one");
    rs.push_back("two");
    rs.push_back("three");
    rs.push_back("four");
    rs.push_back("five");

    Ring<string>::iterator it = rs.begin();

    it++;
    it++;

    it.insert("six");
    it = rs.begin();

    // Twice around the ring:
    for (int i = 0; i < rs.size()*2; i++) {
        cout << *it++ << endl;
    }

    return 0;
} ///:~
