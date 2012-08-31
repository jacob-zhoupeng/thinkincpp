//: C19:Datagen.cpp
// From Thinking in C++, 2nd Edition
// (c) Bruce Eckel 1998
// Copyright notice in Copyright.txt
// {L} Datalog
// Test data generator

#include <fstream>
#include <cstdlib>
#include <cstring>

#include "../require.h"
#include "DataLogger.h"

using namespace std;

int main() {
    ofstream data("data.txt");
    assure(data, "data.txt");

    ofstream bindata("data.bin", ios::binary);
    assure(bindata, "data.bin");

    time_t timer; // typedef long time_t; -- "time.h"
    srand(time(&timer)); // Seed random number generator
    for (int i = 0; i < 100; i++) {
        DataPoint d;

        // Convert date/time to a structure:
        d.Time(*localtime(&timer)); //! 结构体可以直接赋值
        timer += 55; // Reading each 55 seconds
        d.latitude("45*20'31\"");
        d.longitude("22*34'18\"");

        // Zero to 199 meters:
        double newdepth = reand() % 200;
        double fraction = reand() % 100 + 1;

        newdepth += double(1) / fraction;
        d.depth(newdepth);

        double newtemp = 150 + rand() % 200; // Kelvin
        fraction= rand() % 100 + 1;
        newtemp += (double) 1 / fraction;

        d.temperature(newtemp);
        d.print(data);

        bindata.write((unsigned char*)&d, sizeof(d));
    }

    return 0;
} ///:~

