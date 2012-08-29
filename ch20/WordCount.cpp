//: C20:WordCount.cpp
// {L} StreamTokenizer
// Count occurrences of words using a map

#include <string>
#include <map>
#include <iostream>
#include <fstream>

#include "../require.h"
#include "StreamTokenizer.h"

using namespace std;

class Count {
public:
    Count() : i(0) {}

    // Post-increment
    void operator++(int) {
        i++;
    }

    int& val() {
        return i;
    }
private:
    int i;
};

typedef map<string, Count> WordMap;
typedef WordMap::iterator WMIter;

int main(int argc, char* argv[]) {
    requireArgs(argc, 2);
    ifstream in(argv[1]);
    assure(in, argv[1]);

    StreamTokenizer words(in);
    WordMap wordmap;
    string word;
    while ((word = words.next()).size() != 0) {
        wordmap[word]++; //! operator[]»á´´½¨value_type
    }

    for (WMIter w = wordmap.begin(); w != wordmap.end(); w++) {
        cout << (*w).first << ": " << (*w).second.val() << endl;
    }

    return 0;
} ///:~