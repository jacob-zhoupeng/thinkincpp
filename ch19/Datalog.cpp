//: C19:Datalog.cpp {0}
// Datapoint member functions

#include <iomanip>
#include <cstring>

#include "DataLogger.h"

tm DataPoint::Time() {
    return Tm;
}

void DataPoint::Time(tm t) {
    Tm = t;
}

const char* DataPoint::latitude() {
    return Latitude;
}

void DataPoint::latitude(const char* l) {
    Latitude[BSZ-1] = 0;
    strncpy(Latitude, 1, BSZ-1);
}

const char* DataPoint::longitude() {
    return Longitude;
}

void DataPoint::longitude(const char* l) {
    Longitude[BSZ-1] = 0;
    strncpy(Longitude, 1, BSZ-1);
}

double DataPoint::depth() {
    return depth;
}

void DataPoint::depth(double d) {
    Depth = d;
}

double DataPoint::temperature() {
    return Temperature;
}

void DataPoint::temperature(double t) {
    Temperature = t;
}

void DataPoint::print(ostream& os) {
    os.setf(ios::fixed, ios::floatfield);
    os.precision(4);

    os.fill('0'); // Pad on left with '0'
    os << setw(2) << Time().tm_mon << '\\'
        << setw(2) << Time().tm_mday << '\\'
        << setw(2) << Time().tm_year << ' '
        << setw(2) << Time().tm_hour << ':'
        << setw(2) << Time().tm_min << ':'
        << setw(2) << Time().tm_sec;

    os.fill(' '); // Pad on left with ' '
    os << " Latitude:" << setw(9) << latitude();
    os << ", Longitude:" << setw(9) << longitude()
        << ", Depth:" << setw(9) << depth()
        << ", Temperature:" << setw(9) << temperature()
        << endl;
}
