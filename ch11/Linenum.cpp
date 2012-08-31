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
    const int bsz = 100; //! ԭ����룺const bsz = 100;
    char buf[bsz];
    int line = 0;

    while (text.getline(buf, bsz) != NULL) {
        out.setf(ios::right, ios::adjustfield); // �����Ҷ��룬�Զ�����
        out.width(2); // ���ÿ��Ϊ2���ַ�
        out << ++line << ") " << buf << endl;
    }

    return 0;
} ///:~
