//: C20:WordSet.cpp

#include <string>
#include <fstream>
#include <iostream>
#include <set>
#include <iterator>

#include "../require.h"

using namespace std;

int main(int argc, char* argv[]) {
    requireArgs(argc, 2);
    ifstream source(argv[1]);
    assure(source, argv[1]);

    string word;
    set<string> words;
    while (source >> word) {
        words.insert(word);
    }

    copy(words.begin(), words.end(), ostream_iterator<string>(cout, "\n"));
    cout << "Number of unique words:" << words.size() << endl;

    return 0;
} ///:~

