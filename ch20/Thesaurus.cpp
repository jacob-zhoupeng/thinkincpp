//: C20:Thesaurus.cpp
// A map of vectors

#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <ctime>
#include <cstdlib>

#include "assocGen.h"

using namespace std;

typedef map<string, vector<string> > Thesaurus;
typedef pair<string, vector<string> > TEntry;
typedef Thesaurus::iterator TIter;

ostream& operator<<(ostream& os, TEntry t) {
    os << t.first << ": ";

    vector<string>& v = t.second;

    for (int i = 0; i < v.size(); i++) {
        os << v[i] << " ";
    }
    
    return os;
}

// A generator for thesaurus test entries:
class ThesaurusGen {
public:
    ThesaurusGen() {
        srand(time(0));
    }

    TEntry operator()() {
        TEntry result;

        if (count >= maxSize()) {
            count = 0;
        }

        result.first = letters[count++];
        int entries = (rand() % 5) + 2;

        for (int i = 0; i < entries; i++) {
            int choice = rand() % maxSize();
            char cbuf[2] = { 0 };
            cbuf[0] = letters[choice];
            result.second.push_back(cbuf);
        }

        return result;
    }
private:
    static const string letters;
    static int count;

    
    int maxSize() {
        return letters.size();
    }
};

int ThesaurusGen::count = 0;
const string 
ThesaurusGen::letters("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz");

int main(int argc, char* argv[]) {
    Thesaurus thesaurus;

    // Fill with 10 entries:
    generate_n(inserter(thesaurus, thesaurus.begin()), 10, ThesaurusGen());

    // Print everything:
    copy(thesaurus.begin(), thesaurus.end(), ostream_iterator<TEntry>(cout, "\n"));

    // Ask for a "word" to look up:
    while (true) {
        cout << "Select a \"word\", 0 to quit: ";
        for (TIter it = thesaurus.begin(); it != thesaurus.end(); it++) {
            cout << (*it).first << ' ';
        }
        cout << endl;

        string reply;
        cin >> reply;

        // Quit
        if (reply.at(0) == '0') {
            return 0;
        }

        // Not in list, try again
        if (thesaurus.find(reply) == thesaurus.end()) {
            continue;
        }

        vector<string>& v = thesaurus[reply];
        copy(v.begin(), v.end(), ostream_iterator<string>(cout, " "));
        cout << endl;
    }

    return 0;
} ///:~
