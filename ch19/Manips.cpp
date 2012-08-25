//: C19:Manips.cpp
// FORMAT.CPP using manipulators

#include <fstream>
#include <iomanip>

using namespace std;

int main() {
    ofstream trc("trace.out");
    int i = 47;
    float f = 2300114.414159;
    char* s = "Is there any more?";

    trc << setiosflags(ios::unitbuf /* | ios::stdio */ ///  ?????
        | ios::showbase | ios::uppercase
        | ios::showpos);

    trc << i << endl; // Default to dec
    trc << hex << i << endl;
    trc << resetiosflags(ios::uppercase) << oct << i << endl;
    trc.setf(ios::left, ios::adjustfield);
    trc << resetiosflags(ios::showbase) << dec << setfill('0');
    trc << "file char: " << trc.fill() << endl;
    trc << setw(10) << i << endl;
    trc.setf(ios::right, ios::adjustfield);
    trc << setw(10) << i << endl;
    trc.setf(ios::internal, ios::adjustfield);
    trc << setw(10) << i << endl;
    trc << i << endl; // Without setw(10)

    trc << resetiosflags(ios::showpos) << setiosflags(ios::showpoint)
        << "prec = " << trc.precision() << endl;
    trc.setf(ios::scientific, ios::floatfield);
    trc << f << endl;
    trc.setf(ios::scientific, ios::floatfield);
    trc << f << endl;
    trc.setf(ios::fixed, ios::floatfield);
    trc << f << endl;
    // trc.setf(0, ios::floatfield); // Automatic
    trc << f << endl;

    trc << setprecision(20);
    trc << "prec = " << trc.precision() << endl;
    trc << f << endl;
    trc.setf(ios::scientific, ios::floatfield);
    trc << f << endl;
    trc.setf(ios::fixed, ios::floatfield);
    trc << f << endl;
    // trc.setf(0, ios::floatfield); // Automatic
    trc << f << endl;

    trc << setw(10) << s << endl;
    trc << setw(40) << s << endl;
    trc.setf(ios::left, ios::adjustfield);
    trc << setw(40) << s << endl;

    trc << resetiosflags(ios::showpoint | ios::unitbuf
        // | ios::stdio // ???????????
    );

    return 0;
} ///:~

