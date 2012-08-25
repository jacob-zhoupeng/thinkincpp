//: C05:Nestfrnd.cpp
// Nested friends

#include <cstdio>
#include <cstring> // memset()

using namespace std;

#define SZ (20)

struct holder {
public:
    void initialize();

    struct pointer {
public:
        void initialize(holder *H);
        // Move around in the array:
        void next();
        void previous();
        void top();
        void end();
        // Access values:
        int read();
        void set(int i);
private:
        holder *h;
        int *p;
    };
    friend struct holder::pointer; //! ORIGINAL SRC: friend holder::pointer

private:
    int a[SZ];
};

void holder::initialize() {
    memset(a, 0, SZ * sizeof(int));
}

void holder::pointer::initialize(holder *H) {
    h = H;
    p = h->a;
}

void holder::pointer::next() {
    if (p < &(h->a[SZ-1])) {
        p++;
    }
}

void holder::pointer::previous() {
    if (p > &(h->a[0])) {
        p--;
    }
}

void holder::pointer::top() {
    p = &(h->a[0]);
}

void holder::pointer::end() {
    p = &(h->a[SZ-1]);
}

int holder::pointer::read() {
    return *p;
}

void holder::pointer::set(int i) {
    *p = i;
}

int main() {
    holder h;
    holder::pointer hp;
    holder::pointer hp2;
    int i;

    h.initialize();
    hp.initialize(&h);
    hp2.initialize(&h);

    for (i = 0; i < SZ; i++) {
        hp.set(i);
        hp.next();
    }
    hp.top();

    // Print in reverse
    hp2.end();
    for (i = 0; i < SZ; i++) {
        printf("hp = %d, hp2 = %d\n", hp.read(), hp2.read());
        hp.next();
        hp2.previous();
    }

    return 0;
} ///:~
