//: C23:Cleanup.cpp
// Exceptions clean up objects
#include <fstream>
#include <exception>
#include <cstring>

using namespace std;

ofstream out("cleanup.out");

class Noisy {
public:
    Noisy(const char* nm = "array elem") throw(int) {
        objnum = i++;

        memset(name, 0, sz);
        strncpy(name, nm, sz-1);
        out << "constructing Noisy " << objnum 
            << " name [" << name << "]" << endl;

        if (5 == objnum) {
            throw int(5);
        }

        // Not in exception specification:
        if ('z' == *nm) {
            throw char('z');
        }
    }

    ~Noisy() {
        out << "destructing Noisy " << objnum
            << " name [" << name << "]" << endl;
    }

    void* operator new[](size_t sz) {
        out << "Noisy::new[]" << endl;
        return ::new char[sz];
    }

    void operator delete[](void* p) {
        out << "Nosy::delete[]" << endl;
        // ::delete[] p; //! gcc-4.6±àÒë²»Í¨¹ý
        ::delete[] (char*)p;
    }
private:
    static int i;
    int objnum;
    enum {
        sz = 40
    };
    char name[sz];
};

int Noisy::i = 0;

void unexpected_rethrow() {
    out << "inside unexpected_rethrow()" << endl;
    throw; // Rethrow same exception
}

int main(int argc, char* argv[]) {
    set_unexpected(unexpected_rethrow);
    
    try {
        Noisy n1("before array");

        // Throws exception:
        Noisy* array = new Noisy[7];
        Noisy n2("after array");
    } catch (int i) {
        out << "caught " << i << endl;
    }

    out << "testing unexpected:" << endl;

    try {
        Noisy s3("before unexpected");
        Noisy s4("z");
        Noisy n5("after unexpected");
    } catch (char c) {
        out << "caught " << c << endl;
    }

    return 0;
} ///:~