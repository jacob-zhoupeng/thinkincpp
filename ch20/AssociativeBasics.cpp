//: C20:AssociativeBasics.cpp
// Basic operations with sets and maps

#include <iostream>
#include <iterator>
#include <set>
#include <map>

#include "Noisy.h"

using namespace std;

int main(int argc, char* argv[]) {
    Noisy na[] = { Noisy(), Noisy(), Noisy(), Noisy(), 
        Noisy(), Noisy(), Noisy() };

    // Add elements via constructor:
    set<Noisy> ns(na, na+sizeof(na)/sizeof(Noisy));

    // Ordinary insertion:
    Noisy n;
    ns.insert(n);
    cout << endl;

    // Check for set membership:
    cout << "ns.count(n) = " << ns.count(n) << endl;

    if (ns.find(n) != ns.end()) {
        cout << "n(" << n << ") found in ns" << endl;
    }

    // Print elements:
    copy(ns.begin(), ns.end(), ostream_iterator<Noisy>(cout, " "));
    cout << endl;

    cout << "\n----------\n";
    
    map<int, Noisy> nm;
    for (int i = 0; i < 10; i++) {
        nm[i]; // Automatically makes pairs
    }

    cout << "\n----------\n";

    for (int j = 0; j < nm.size(); j++) {
        cout << "nm[" << j << "] = " << nm[j] << endl;
    }
    
    cout << "\n----------\n";

    nm[10] = n;

    cout << "\n----------\n";

    nm.insert(make_pair(47, n));

    cout << "\n----------\n";

    cout << endl << "nm.count(10) = " << nm.count(10) << endl;
    cout << "nm.count(11) = " << nm.count(11) << endl;

    map<int, Noisy>::iterator it = nm.find(6);

    if (it != nm.end()) {
        cout << "value:" << (*it).second 
            << " found in nm at location 6" << endl;
    }

    for (it = nm.begin(); it != nm.end(); it++) {
        cout << (*it).first << ":" << (*it).second << ", ";
    }

    cout << "\n----------\n";

    return 0;
} ///:~
