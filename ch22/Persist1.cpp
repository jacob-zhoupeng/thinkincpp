//: C22:Persist1.cpp
// Simple persistence with MI
#include <iostream>
#include <fstream>

#include "../require.h"

using namespace std;

class Persistent {
public:
    Persistent(int sz) : objSize(sz) {}

    void write(ostream& out) const {
        out.write((char*)this, objSize);
    }

    void read(istream& in) {
        in.read((char*)this, objSize);
    }
private:
    int objSize; // Size of stored object
};

class Data {
public:
    Data(float f0 = 0.0, float f1 = 0.0, float f2 = 0.0) {
        f[0] = f0;
        f[1] = f1;
        f[2] = f2;
    }

    void print(const char* msg = "") const {
        if (*msg) {
            cout << msg << "\n";
        }
        for (int i = 0; i < 3; i++) {
            cout << "f[" << i << "] = " << f[i] << endl;
        }
    }
private:
    float f[3];
};

class WData1 : public Persistent, public Data {
public:
    WData1(float f0 = 0.0, float f1 = 0.0, float f2 = 0.0)
        : Data(f0, f1, f2), Persistent(sizeof(WData1)) {}
};

class WData2 : public Data, public Persistent {
public:
    WData2(float f0 = 0.0, float f1 = 0.0, float f2 = 0.0)
        : Data(f0, f1, f2), Persistent(sizeof(WData2)) {}
};

int main(int argc, char* argv[]) {
    {
        ofstream f1("f1.dat");
        ofstream f2("f2.dat");

        WData1 d1(1.1, 2.2, 3.3);
        WData2 d2(4.4, 5.5, 6.6);

        d1.print("d1 before storage");
        d2.print("d2 before storage");

        d1.write(f1);
        d2.write(f2);
    } // Closes files

    ifstream f1("f1.dat");
    ifstream f2("f2.dat");

    assure(f1, "f1.dat");
    assure(f2, "f2.dat");

    WData1 d1;
    WData2 d2;

    d1.read(f1);
    d2.read(f2);

    d1.print("d1 after storage");
    d2.print("d2 after storage");

    return 0;
} ///:~