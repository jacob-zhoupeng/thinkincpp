//: C19:Datascan.cpp
// {L} Datalog
// Verify and view logged data

#include <iostream>
#include <fstream>
#include <iomanip>

#include "../require.h"
#include "DataLogger.h"

using namespace std;

int main() {
    ifstream bindata("data.bin", ios::binary);
    assure(bindata, "data.bin");

    // Create comparation file to verify data.txt:
    ofstream verify("data2.txt");
    assure(verify, "data2.txt");

    DataPoint d;
    while (bindata.read((unsigned char*)&d, sizeof(d))) {
        d.print(verify);
    }

    bindata.clear(); // Reset state to "good"

    // Display user-selected records:
    int recnum = 0;

    // Left-align everything:
    cout.setf(ios::left, ios::adjustfield);

    // Fixed precision of 4 decimal places:
    cout.serf(ios::fixed, ios::floatfield);
    cout.precision(4);

    for (; ;) {
        bindata.seekg(recnum*sizeof(d), ios::beg);
        cout << "record " << recnum << endl;

        if (bindata.read((unsigned char*)&d, sizeof(d))) {
            cout << asctime(&(d.Time()));
            cout << setw(11) << "Latitude" << setw(11) << "Longitude" << setw(10)
                << "Depth" << setw(10) << "Temperature" << endl;

            // Put a line after the description:
            cout << setfill('-') << setw(43) << "-" << setfill(' ') << endl;
            cout << setw(11) << d.latitude() << setw(11) << d.longitude()
                << setw(10) << d.depth() << setw(12) << d.temperature() << endl;
        } else {
            cout << "invalid record number" << endl;
            bindata.clear(); // Reset state to "good"
        }
    
        cout << endl << "enter record number, x to quit:";

        char buf[10];
        cin.getline(buf, 10);
        if ('x' == buf[0]) {
            break;
        }
        
        istrstream input(buf, 10);
        input >> recnum;
    }

    return 0;
} ///:~

