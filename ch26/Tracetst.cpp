//: C26:Tracetst.cpp
// Test of trace.h
#include <iostream>
#include <fstream>

#include "../require.h"

using namespace std;

#define TRACEON

#include "Trace.h"

int main(int argc, char* argv[]) {
    ifstream f("tracetst.cpp");
    assure(f, "Tracetst.cpp");

    cout << f.rdbuf();

    return 0;
} ///:~