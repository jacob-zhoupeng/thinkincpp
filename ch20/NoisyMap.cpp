//: C20:NoisyMap.cpp
// Mapping Noisy to Noisy

#include <map>

#include "Noisy.h"

using namespace std;

int main(int argc, char* argv[]) {
    map<Noisy, Noisy> mnn;

    Noisy n1;
    Noisy n2;

    cout << "\n----------\n";

    //! map has fancy "make a new entry if 
    //! one isn't there" beahvior
    mnn[n1] = n2; 
    cout << "\n----------\n";

    cout << mnn[n1] << endl;
    cout << "\n----------\n";

    return 0;
} ///:~
