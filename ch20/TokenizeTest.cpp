//: C20:TokenizeTest.cpp
// {L} StreamTokenizer
// Test StreamTokenzier

#include <iostream>
#include <fstream>
#include <set>

#include "../require.h"
#include "StreamTokenizer.h"

using namespace std;

int main(int argc, char* argv[]) {
    //requireArgs(argc, 2);
    //ifstream in(argv[1]);
    ifstream in(__FILE__);
    assure(in, argv[1]);

    StreamTokenizer words(in);
    set<string> wordlist;
    string word;

    while ((word = words.next()).size() != 0) {
        wordlist.insert(word);
    }

    // Output results:
    copy(wordlist.begin(), wordlist.end(), ostream_iterator<string>(cout, "\n"));

    return 0;
} ///:~

