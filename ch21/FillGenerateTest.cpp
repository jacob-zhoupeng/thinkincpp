//: C21:FillGenerateTest.cpp
// Demonstrates "fill" and "generate"

#include <vector>
#include <string>
#include <algorithm>

#include "Generators.h"
#include "PrintSequence.h"

using namespace std;

int main(int argc, char* argv[]) {
    vector<string> v1(5);

    fill(v1.begin(), v1.end(), "howdy");
    print<string>(v1, "v1", " ");

    vector<string> v2;
    fill_n(back_inserter(v2), 7, "bye");
    print<string>(v2.begin(), v2.end(), "v2");

    vector<int> v3(10);
    generate(v3.begin(), v3.end(), SkipGen(4, 5));
    print<int>(v3, "v3", " ");

    vector<int> v4;
    generate_n(back_inserter(v4), 15, URandGen(30));
    print<int>(v4, "v4", " ");
    
    return 0;
} ///:~