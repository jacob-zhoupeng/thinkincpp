//: C21:BikeTest.cpp
// {L} Bicycle
#include <algorithm>

#include "Bicycle.h"

using namespace std;

int main(int argc, char* argv[]) {
    vector<Bicycle*> bikes;
    BicycleGenerator bg;

    generate_n(back_inserter(bikes), 12, bg);
    Bicycle::print(bikes);

    return 0;
} ///:~