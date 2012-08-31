//: C19:DataLogger.h
// Datalogger record layout
#ifndef DATALOG_H_
#define DATALOG_H_

#include <ctime>
#include <iostream>

#define BSZ (10)

class DataPoint {
public:
    tm Time(); // Read the time
    void Time(tm t); // Set the time

    const char* latitude(); // Read
    void latitude(const char* l); // Set

    const char* longitude(); // Read
    void longitude(const char* l); // Set

    double depth(); // Read
    void depth(double d); // Set

    double temperature(); // Read
    void temperature(double t); // Set

    void print(ostream& os);
private:
    tm Tm; // Time & day
    // Ascii degrees (*) minutes (') seconds ("):
    char Latitude[BSZ];
    char Longitude[BSZ];
    double Depth;
    double Temperature;
};

#endif // DATALOG_H_
///:~

