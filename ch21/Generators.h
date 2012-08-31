//: C21:Generators.h
// Different ways to fill sequences

#ifndef GENERATORS_H_
#define GENERATORS_H_

#include <set>
#include <cstdlib>
#include <ctime>
#include <cstring>

// A generator that can skip over numbers:
class SkipGen {
public:
    SkipGen(int start = 0, int skip = 1) : i(start), skp(skip) {}

    int operator()() {
        int r = i;
        i += skp;
        return r;
    }
private:
    int i;
    int skp;
};

// Generate unique random numbers from 0 to mod:
class URandGen {
public:
    URandGen(int mod) : modulus(mod) {
        std::srand(std::time(0));
    }

    int operator()() {
        while (true) {
            int i = (int) std::rand() % modulus;
            if (used.find(i) == used.end()) {
                used.insert(i);
                return i;
            }
        }
    }
private:
    std::set<int> used;
    int modulus;
};

// Produces random characters:
class CharGen {
public:
    CharGen() {
        std::srand(std::time(0));
    }

    char operator()() {
        return source[std::rand() % len];
    }
private:
    static const char* source;
    static const int len;
};

//! Statics created here for convenience, but
//! will cause problems if multiply included:
const char* CharGen::source = 
                        "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
const int CharGen::len = std::strlen(source);

#endif // GENERATORS_H_ ///:~