//: C23:Nudep.cpp
// Naked pointers
#include <fstream>
#include <cstdlib>

using namespace std;

ofstream out("nudep.out");

class Cat {
public:
    Cat() {
        out << "Cat()" << endl;
    }

    ~Cat() {
        out << "~Cat()" << endl;
    }
};

class Dog {
public:
    void* operator new(size_t sz) {
        out << "allocating an Dog" << endl;
        throw int(47);
        return 0;
    }

    void operator delete(void* p) {
        out << "deallocating an Dog" << endl;
        ::delete p;
    }
};

class UseResources {
public:
    UseResources(int count = 1) {
        out << "UseResources()" << endl;
        bp = new Cat[count];
        op = new Dog;
    }
    
    ~UseResources() {
        out << "~UseResource()" << endl;
        delete[] bp; // Array delete
        delete op;
    }
private:
    Cat* bp;
    Dog* op;
};

int main(int argc, char* argv[]) {
    try {
        UseResources ur(3);
    } catch (int) {
        out << "inside handler" << endl;
    }

    return 0;
} ///:~