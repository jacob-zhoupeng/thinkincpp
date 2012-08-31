//: C19:NumberPhotos.cpp
// Find the marker "XXX" and replace it with an
// incrementing number whereever it appears. Used
// to help format a web page with photos in it

#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>

#include "../require.h"

using namespace std;

int main(int argc, char* argv[]) {
    requireArgs(argc, 3);
    ifstream in(argv[1]);
    assure(in, argv[1]);

    ofstream out(argv[2]);
    assure(out, argv[2]);

    string line;
    int counter = 1;
    while (getline(in, line)) {
        unsigned int xxx = line.find("XXXX");

        if (xxx != string::npos) {
            ostringstream cntr;
            cntr << setfill('0') << setw(3) << counter++;
            line.replace(xxx, 3, cntr.str());
        }
        out << line << endl;
    }

    return 0;
} ///:~

