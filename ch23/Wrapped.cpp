//: C23:Wrapped.cpp
// Safe, atomic pointers
#include <fstream>
#include <cstdlib>

using namespace std;

ofstream out("wrapped.out");

// Simplified. Yours may have other arguments.
template<class T, int sz = 1>
class PWrap {
public:
    class RangeError {}; // Exception class

    PWrap() {
        ptr = new T[sz];
        out << "PWrap constructor" << endl;
    }

    ~PWrap() {
        delete[] ptr;
        out << "PWrap destructor" << endl;
    }

    T& operator[](int i) throw(RangeError) {
        if (i >= 0 && i < sz) {
            return ptr[i];
        } else {
            throw RangeError();
        }
    }
private:
    T* ptr;
};

class Cat {
public:
    Cat() {
        out << "Cat()" << endl;
    }

    ~Cat() {
        out << "~Cat()" << endl;
    }

    void g() {}
};

class Dog {
public:
    void* operator new[](size_t sz) {
        out << "allocating an Dog" << endl;
        throw int(47);
        return 0;
    }

    void operator delete[](void* p) {
        out << "deallocating an Dog" << endl;
        ::delete (char*)p;
    }
};

class UseResources {
public:
    UseResources() : Bonk(), Og() {
        out << "UseResources()" << endl;
    }

    ~UseResources() {
        out << "~UseResources()" << endl;
    }

    void f() {
        Bonk[1].g();
    }
private:
    PWrap<Cat, 3> Bonk;
    PWrap<Dog> Og;
};

int main(int argc, char* argv[]) {
    try {
        UseResources ur;
    } catch (int) {
        out << "inside handler" << endl;
    } catch (...) {
        out << "inside catch(...)" << endl;
    }

    return 0;
} ///:~