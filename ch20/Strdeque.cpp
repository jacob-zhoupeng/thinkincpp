//: C20:Strdeque.cpp
// Converted from Strvector.cpp

#include <string>
#include <deque>
#include <vector>
#include <fstream>
#include <iostream>
#include <iterator>
#include <sstream>
#include <ctime>

#include "../require.h"

using namespace std;

int main(int argc, char* argv[]) {
    requireArgs(argc, 2);
    ifstream in(argv[1]);
    assure(in, argv[1]);

    vector<string> vstrings;
    deque<string> dstrings;

    string line;

    // Time reading into vector:
    clock_t ticks = clock();
    while (getline(in, line)) {
        vstrings.push_back(line);
    }
    ticks = clock() - ticks;
    cout << "Read into vector: " << ticks << endl;

    in.close();

    // Repeat for deque:
    ifstream in2(argv[1]);
    assure(in2, argv[1]);

    ticks = clock();
    while (getline(in2, line)) {
        dstrings.push_back(line);
    }
    ticks = clock() - ticks;
    cout << "Read into deque: " << ticks << endl;

    // Now compare indexing:
    ticks = clock();
    for (int i = 0; i < vstrings.size(); i++) {
        ostringstream ss;
        ss << i;
        vstrings[i] = ss.str() + ": " + vstrings[i];
    }
    ticks = clock() - ticks;
    cout << "Indexing vector: " << ticks << endl;

    ticks = clock();
    for (int j = 0; j < dstrings.size(); j++) {
        ostringstream ss;
        ss << j;
        dstrings[j] = ss.str() + ": " + dstrings[j];
    }
    ticks = clock() - ticks;
    cout << "Indexing deque: " << ticks << endl;

    // Compare iteration:
    ofstream tmp1("tmp1.tmp");
    ofstream tmp2("tmp2.tmp");

    ticks = clock();
    copy(vstrings.begin(), vstrings.end(), ostream_iterator<string>(tmp1, "\n"));
    ticks = clock() - ticks;
    cout << "Iterating vector: " << ticks << endl;

    ticks = clock();
    copy(dstrings.begin(), dstrings.end(), ostream_iterator<string>(tmp2, "\n"));
    ticks = clock() - ticks;
    cout << "Iterating deque: " << ticks << endl;

    return 0;
} ///:~

