//: C16:TStash.h
// PSTASH using templates
#ifndef TSTASH_H_
#define TSTASH_H_

#include <cstdlib>

#include "../require.h"

// More convenient than nesting in TStash:
enum owns {
    no = 0, yes = 1, Default
};

// Declaration required:
template<class Type, int sz>
class TStashIter;

template<class Type, int chunksize = 20>
class TStash {
public:
    TStash(owns Owns = yes);
    ~TStash();
    int Owns() const {
        return own;
    }
    void Owns(owns newOwns) {
        own = newOwns;
    }
    int add(Type *element);
    int remove(int index, owns d = Default);
    Type *operator[](int index);
    int count() const {
        return next;
    }
    friend class TStashIter<Type, chunksize>;
protected:
    Type **storage;
private:
    int quantity;
    int next;
    owns own; // Flag
    void inflate(int increase = chunksize);
};

template<class Type, int sz = 20>
class TStashIter {
public:
    TStashIter(TStash<Type, sz> &TS) : ts(TS), index(0) {
        // Empty body
    }

    TStashIter(const TStashIter &rv) : ts(rv.ts), index(rv.index) {
        // Empty body
    }

    // Jump iterator forward or backward:
    void forward(int amount) {
        index += amount;
        if (index >= ts.next) {
            index = ts.next-1;
        }
    }

    void backward(int amount) {
        index -= amount;
        if (index < 0) {
            index = 0;
        }
    }

    // Return value of ++ and -- to be
    // used inside conditionals:
    int operator++() {
        if (++index >= ts.next) {
            return 0;
        }
        return 1;
    }

    int operator++(int) {
        return operator++();
    }

    int operator--() {
        if (--index < 0) {
            return 0;
        }
        return 1;
    }

    int operator--(int) {
        return operator--();
    }

    operator int() {
        return index >= 0 && index < ts.next;
    }

    Type *operator->() {
        Type *t = ts.storage[index];
        if (t) {
            return t;
        }
        require(0, "TStashIter::operator->return 0");
        return 0; // To allow inlining
    }

    // Remove the current element:
    int remove(owns d = Default) {
        return ts.remove(index, no);
    }
private:
    TStash<Type, sz> &ts;
    int index;
};

template<class Type, int sz>
TStash<Type, sz>::TStash(owns Owns) : own(Owns) {
    quantity = 0;
    storage = NULL;
    next = 0;
}

// Destruction of contained objects:
template<class Type, int sz>
TStash<Type, sz>::~TStash() {
    if (storage == NULL) {
        return;
    }
    if (own == yes) {
        for (int i = 0; i < count(); i++) {
            delete storage[i];
        }
    }
    free(storage);
}

template<class Type, int sz>
int TStash<Type, sz>::add(Type *element) {
    if (next >= quantity) {
        inflate();
    }
    storage[next++] = element;
    return (next - 1); // Index number
}

template<class Type, int sz>
int TStash<Type, sz>::remove(int index, owns d) {
    if (index >= next || index < 0) {
        return 0;
    }

    switch(d) {
    case Default:
        if (own != yes) {
            break;
        }
    case yes:
        delete storage[index];
    case no:
        storage[index] = 0; // Position is empty
    }

    return 1;
}

template<class Type, int sz>
inline Type *TStash<Type, sz>::operator[](int index) {
    // Remove check for shipping application:
    require(index >= 0 && index < next);
    return storage[index];
}

template<class Type, int sz>
void TStash<Type, sz>::inflate(int increase) {
    void *v = realloc(storage, (quantity+increase)*sizeof(Type *));
    require(v != 0); // Was it successful?
    storage = (Type **)v;
    quantity += increase;
}

#endif // TSTASH_H_ ///:~
