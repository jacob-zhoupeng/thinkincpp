//: C19:Cppcheck.cpp
// Configures .H & .CPP files
// To conform to style standard.
// Tests existing files for conformance

#include <fstream>
#include <strstream>
#include <cstring>
#include <cctype>

#include "../require.h"

using namespace std;

#define SZ (40) // Buffer sizes
#define BSZ (100)

int main(int argc, char* argv[]) {
    requireArgs(argc, 2); // File set name

    enum bufs {
        base, header, implement,
        Hline1, guard1, guard2, guard3,
        CPPline1, include, bufnum,
    };

    char b[bufnum][SZ];

    ostrstream osarray[] = {
        ostrstream(b[base], SZ),
        ostrstream(b[header], SZ),
        ostrstream(b[implement], SZ),
        ostrstream(b[Hline1], SZ),
        ostrstream(b[guard1], SZ),
        ostrstream(b[guard2], SZ),
        ostrstream(b[guard3], SZ),
        ostrstream(b[CPPline1], SZ),
        ostrstream(b[include], SZ),
    };

    osarray[base] << argv[1] << ends;

    // Find any '.' in the string using the
    // Standard C library function strchr():
    char* period = strchr(b[base], '.');
    if (period) {
        *period = 0; // Strip extension
    }

    // Force to upper case:
    for (int i = 0; '\0' != b[base][i]; i++) {
        b[base][i] = toupper(b[base][i]);
    }

    // Create file names and internal lines:
    osarray[header] << b[base] << ".H" << ends;
    osarray[implement] << b[base] << ".CPP" << ends;
    osarray[Hline1] << "//" << ": " << b[header] << " -- " << ends;
    osarray[guard1] << "#ifndef " << b[base] << "_H_" << ends;
    osarray[guard2] << "#define " << b[base] << "_H_" << ends;
    osarray[guard3] << "#endif // " << b[base] << "_H_" << ends;
    osarray[CPPline1] << "//" << ": " << b[implement] << " -- " << ends;
    osarray[include] << "#include \"" << b[header] << "\"" << ends;

    // First, try to open existing files:
    ifstream existh(b[header]);
    ifstream existcpp(b[implement]);

    if (!existh) { // Doesn't exist; create it
        ofstream newheader(b[header]);
        assure(newheader, b[header]);
        newheader << b[Hline1] << endl << b[guard1] << endl
            <<  b[guard2] << endl << endl << b[guard3] << endl;
    }

    if (!existcpp) { // Create cpp file
        ofstream newcpp(b[implement]);
        assure(newcpp, b[implement]);
        newcpp << b[CPPline1] << endl << b[include] << endl;
    }

    if (existh) { // Already exists; verify it
        strstream hfile; // Write & read
        ostrstream newHeader; // Write
        hfile << existh.rdbuf() << ends;

        // Check that first line conforms:
        char buf[BSZ];
        if (hfile.getline(buf, BSZ)) {
            if (!strstr(buf, "//" ":") ||
                !strstr(buf, b[header])) {
                newHeader << b[Hline1] << endl;
            }
        }

        // Ensure guard lines are in header:
        if (!strstr(hfile.str(), b[guard1]) ||
                !strstr(hfile.str(), b[guard2]) ||
                !strstr(hfile.str(), b[guard3])) {
            newHeader << b[guard1] << endl << b[guard2] << endl
                << buf << hfile.rdbuf() << endl << b[guard3] << endl << ends;
        } else {
            newHeader << buf << hfile.rdbuf() << ends;
        }

        //If there were changes, overwrite file:
        if (strcmp(hfile.str(), newHeader.str()) != 0) {
            existh.close();
            ofstream newH(b[header]);
            assure(newH, b[header]);
            newH << "//@//" << endl // Change marker
                << newHeader.rdbuf();
        }

        delete hfile.str();
        delete newHeader.str();
    }

    if (existcpp) { // Already exists; verify it
        strstream cppfile;
        ostrstream newcpp;

        cppfile << existcpp.rdbuf() << ends;

        // Check that first line conforms:
        char buf[BSZ];
        if (cppfile.getline(buf, BSZ)) {
            if (!strstr(buf, "//" ":") ||
                    !strstr(buf, b[implement])) {
                newcpp << b[CPPline1] <<endl;
            }
        }

        // Ensure header file included:
        if (!strstr(cppfile.str(), b[include])) {
            newcpp << b[include] << endl;
        }

        // Put in the reset of the file:
        newcpp << buf << endl; // First line read
        newcpp << cppfile.rdbuf() << ends;

        // If there were change, overwrite file:
        if (strcmp(cppfile.str(), newcpp.str()) != 0) {
            existcpp.close();
            ofstream newCPP(b[implement]);
            assure(newCPP, b[implement]);
            newCPP << "//@//" << endl // Change marker
                << newcpp.rdbuf();
        }

        delete cppfile.str();
        delete newcpp.str();
    }

    return 0;
} ///:~

