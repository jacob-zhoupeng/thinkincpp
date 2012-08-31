//: C19:Breakup.cpp
// Breaks a file up into smaller files for
// easier downloads

#include <iostream>
#include <fstream>
#include <iomanip>
#include <strstream>
#include <string>

#include "../require.h"

using namespace std;

int main(int argc, char* argv[]) {
    requireArgs(argc, 2);

    ifstream in(argv[1], ios::binary);
    assure(in, argv[1]);

    in.seekg(0, ios::end); // End of file
    long fileSize = in.tellg(); // Size of file
    cout << "file size = " << fileSize << endl;

    in.seekg(0, ios::beg); // Start of file
    char* fbuf = new char[fileSize];
    require(0 != fbuf);

    in.read(fbuf, fileSize);
    in.close();

    string infile(argv[1]);
    unsigned int dot = infile.find('.');
    while (dot != string::npos) {
        infile.replace(dot, 1, "-");
        dot = infile.find('.');
    }

    string batchName("DOSAssemble" + infile + ".bat");
    ofstream batchFile(batchName.c_str());
    batchFile << "copy /b ";

    int filecount = 0;
    const int sbufsz = 128;
    char sbuf[sbufsz];
    const long pieceSize = 1000L * 100L;
    long byteCounter = 0;
    while (byteCounter < fileSize) {
        ostrstream name(sbuf, sbufsz);
        name << argv[1] << "-part" << setfill('0')
            << setw(2) << filecount++ << ends;
        cout << "creating " << sbuf << endl;

        if (filecount > 1) {
            batchFile << "+"; 
        }

        batchFile << sbuf;

        ofstream out(sbuf, ios::out | ios::binary);
        assure(out, sbuf);

        long byteq;
        if (byteCounter + pieceSize < fileSize) {
            byteq = pieceSize;
        } else {
            byteq = fileSize - byteCounter;
        }

        out.write(fbuf + byteCounter, byteq);
        cout << "wrote " << byteq << " bytes, ";
        byteCounter += byteq;
        out.close();
        cout << "ByteCounter = " << byteCounter << ", fileSize = "
            << fileSize << endl;        
    }

    batchFile << " " << argv[1] << endl;

    return 0;
} ///:~

