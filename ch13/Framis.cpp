//: C13:Framis.cpp
// Local overloaded new & delete

#include <cstddef> // For size_t
#include <fstream>

using namespace std;

ofstream out("Framis.out");

class Framis {
public:
    enum {
        psize = 100
    }; // # of frami allowed
    Framis() {
        out << "Framis()\n";
    }
    ~Framis() {
        out << "~Framis() ... ";
    }
    //! 对类重载运算符new/delete
    void *operator new(size_t);
    void operator delete(void *);
private:
    char c[10];
    static unsigned char pool[];
    static unsigned char alloc_map[];
};

//! 类静态成员分配空间
unsigned char Framis::pool[psize * sizeof(Framis)];
//! 聚集初始化，设置所有都为0
unsigned char Framis::alloc_map[psize] = { 0 };

// Size is ignored -- assume a Framis object
void *Framis::operator new(size_t) {
    for (int i = 0; i < psize; i++) {
        if (!alloc_map[i]) {
            out << "using block " << i << " ... ";
            alloc_map[i] = 1; // Mark it used
            return pool + (i * sizeof(Framis));
        }
    }
    out << "out of memory" << endl;
    return NULL;
}

void Framis::operator delete(void *m) {
    if (m == NULL) { // Check for null pointer
        return;
    }
    // Assume it was created in the pool
    // Calculate which block number it is:
    unsigned long block = (unsigned long)m - (unsigned long)pool;
    block /= sizeof(Framis);
    out << "freeing block " << block << endl;
    alloc_map[block] = 0; // Mark it free
}

int main() {
    Framis *f[Framis::psize];

    for (int i = 0; i < Framis::psize; i++) {
        f[i] = new Framis;
    }
    new Framis; // Out of memory
    delete f[10];
    f[10] = NULL;

    // Use released memory:
    Framis *x = new Framis;
    delete x;

    for (int j = 0; j < Framis::psize; j++) {
        delete f[j]; // Delete f[10] OK
    }


    return 0;
} ///:~
