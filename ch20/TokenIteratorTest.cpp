//: C20:TokenIteratorTest.cpp

#include <fstream>
#include <iostream>
#include <iterator>
#include <vector>
#include <set>

#include "TokenIterator.h"

using namespace std;

int main(int argc, char* argv[]) {
    ifstream in("TokenIteratorTest.cpp");
    ostream_iterator<string> out(cout, "\n");

    typedef istreambuf_iterator<char> IsbIt;

    IsbIt begin(in);
    IsbIt isbEnd;

    Delimiters delimiters(" \t\n~;()\"<>:{}[]+-=&*#.,/\\");
    TokenIterator<IsbIt, Delimiters> wordIter(begin, isbEnd, delimiters);
    TokenIterator<IsbIt, Delimiters> end;

    vector<string> wordlist;

    copy(wordIter, end, back_inserter(wordlist));

    // Output results:
    copy(wordlist.begin(), wordlist.end(), out);
    out = "--------------------------------------";

    // Use a char array as the source:
    char* cp = "typedef std::istreambuf_iterator<char> It";
    TokenIterator<char*, Delimiters> charIter(cp, cp + strlen(cp), delimiters);
    TokenIterator<char*, Delimiters> end2;

    vector<string> wordlist2;
    copy(charIter, end2, back_inserter(wordlist2));
    copy(wordlist2.begin(), wordlist2.end(), out);
    cout = "--------------------------------------";

    // Use a deque<char> as the source:
    ifstream in2("TokenIteratorTest.cpp");
    deque<char> dc;
    copy(IsbIt(in2), IsbIt(), back_inserter(dc));

    TokenIterator<deque<char>::iterator, Delimiters> dcIter(dc.begin(), dc.end(), delimiters);
    TokenIterator<deque<char>::iterator, Delimiters> end3;

    vector<string> wordlist3;
    copy(dcIter, end3, back_iterator(wordlist3));
    copy(wordlist3.begin(), wordlist3.end(), out);
    out = "----------------------------------------";

    // Reproduce the Wordlist.cpp example:
    ifstream in3("TokenIteratorTest.cpp");
    TokenIterator<IsbIt, Delimiters> wordIter2(IsbIt(in3), isbEnd, delimiters);
    set<string> wordlist4;
    while (wordIter2 != end) {
        wordlist4.insert(*wordIter2++);
    }
    copy(wordlist4.begin(), wordlist4.end(), out);
    
    return 0;
} ///:~

