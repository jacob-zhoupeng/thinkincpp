//: C07:Flags.cpp
// List of true/false flags

#include <cstdio>
#include <cstring>

#include "../require.h"

using namespace std;

#define FSIZE (100)
#define TRUE (1)
#define FALSE (0)

class Flags {
public:
    Flags();
    void set(int i);
    void clear(int i);
    int read(int i);
    int size();
private:
    unsigned char f[FSIZE];
};

Flags::Flags() {
    memset(f, FALSE, FSIZE);
}

void Flags::set(int i) {
    require(i >= 0 && i < FSIZE);
    f[i] = TRUE;
}

void Flags::clear(int i) {
    require(i >= 0 && i < FSIZE);
    f[i] = FALSE;
}

int Flags::read(int i) {
    require(i >= 0 && i < FSIZE);
    return f[i];
}

int Flags::size() {
    return FSIZE;
}

int main() {
    Flags fl;

    for (int i = 0; i < fl.size(); i++) {
        if (i % 3 == 0) {
            fl.set(i);
        }
    }

    for (int j = 0; j < fl.size(); j++) {
        printf("fl.read(%d) = %d\n", j, fl.read(j));
    }
} ///:~
