//: C19:Showerr.cpp
// Un-comment error generators

#include <iostream>
#include <strstream>
#include <cstdio> // int remove(char* fname)
#include <cstring>
#include <cctype>

#include "../require.h"

using namespace std;

char* marker = "//!";

char* usage = "usage: showerr filename chapnum\n"
              "where filename is a C++ source file\n"
              "and chapnum is the chapter name it's in.\n"
              "Finds lines commented with //! and removes \n"
              "comment, appending //(#) where # is unique\n"
              "across all files, so you can determine\n"
              "if your compiler finds the error.\n"
              "showerr /r\n"
              "resets the unique counter.";

// File containing error number counter:
char* errnum = "../errnum.txt";

// File containing error lines:
char* errfile = "../errlines.txt";

ofstream errlines(errfile, ios::app);

int main(int argc, char* argv[1]) {
    if (argc < 2) {
        cerr << usage << endl;
        return 1;
    }

    if ('/' == argv[1][0] || '-' == argv[1][0]) {
        // Allow for other switches:
        switch (argv[1][1]) {
        case 'r': /* FALL THROUGH */
        case 'R':
            cout << "reset counter" << endl;
            remove(errnum); // Delete files
            remove(errfile);
            return 0;
        default:
            cerr << usage << endl;
            return 1;
        }
    }

    char* chapter = argv[2];
    strstream edited; // Edited file
    int counter = 0;
    {
        ifstream infile(argv[1]);
        assure(infile, argv[1]);

        ifstream count(errnum);
        assure(count, errnum);

        if (count) {
            count >> counter;
        }
        
        int linecount = 0;
#define sz (255)
        char buf[sz];
        while (infile.getline(buf, sz)) {
            linecount++;
            // Eat white space:
            int i = 0;
            while (isspace(buf[i])) {
                i++;
            }
            // Find marker at start of line:
            if (strstr(&buf[i], marker) == &buf[i]) {
                // Erase marker:
                memset(&buf[i], ' ', strlen(marker));
                // Append counter & error info:
                ostrstream out(buf, sz, ios::ate);
                cout << "//(" << ++counter << ") "
                     << "Chapter " << chapter << " File: " << argv[1]
                     << " Line: " << linecount << endl << ends;
                edited << buf;
                errlines << buf; // Append error file
            } else {
                edited << buf << "\n"; // Just copy
            }
        }
    } // Closees files

    ofstream outfile(argv[1]); // Overwrites
    assure(outfile, argv[1]);
    outfile << edited.rdbuf();

    ofstream count(errnum); // Overwrites
    assure(count, errnum);
    count << counter; // Save new counter

    return 0;
} ///:~

