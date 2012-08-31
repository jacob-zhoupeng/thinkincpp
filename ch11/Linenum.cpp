//: C11:Linenum.cpp
// Add line numbers

#include <fstream>
#include <strstream> //! Deprecated! replaced by <sstream>
#include <cstdlib>

#include "../require.h"

using namespace std;

int main(int argc, char *argv[]) {
    requireArgs(argc, 2, "Usage: linenum file\n"
                "Adds line numbers to file");
    strstream text;

    {
        ifstream in(argv[1]);
        assure(in, argv[1]);
        text << in.rdbuf(); // Read in whole file
    } // Close file

    ofstream out(argv[1]); // Overwrite file
    assure(out, argv[1]);
    const int bsz = 100; //! 原书代码：const bsz = 100;
    char buf[bsz];
    int line = 0;

    while (text.getline(buf, bsz) != NULL) {
        out.setf(ios::right, ios::adjustfield); // 设置右对齐，自动调整
        out.width(2); // 设置宽度为2个字符
        out << ++line << ") " << buf << endl;
    }

    return 0;
} ///:~
