//: C21:SortedSearchTest.cpp
// {L} ../ch20/StreamTokenizer
// Test searching in sorted ranges

#include <algorithm>
#include <fstream>
#include <queue>
#include <vector>

#include "../ch20/StreamTokenizer.h"
#include "PrintSequence.h"
#include "NString.h"

using namespace std;

int main(int argc, char* argv[]) {
    ifstream in("SortedSearchTest.cpp");
    StreamTokenizer words(in);
    deque<NString> dstr;

    string word;
    while ((word = words.next()).size() != 0) {
        dstr.push_back(NString(word));
    }

    vector<NString> v(dstr.begin(), dstr.end());
    sort(v.begin(), v.end());
    print<NString>(v, "sorted");

    typedef vector<NString>::iterator sit;

    sit it;
    sit it2;
    string f("include");
    cout << "binary search: "
        << binary_search(v.begin(), v.end(), f) << endl;
    it = lower_bound(v.begin(), v.end(), f);
    it2 = upper_bound(v.begin(), v.end(), f);
    print<NString>(it, it2, "found range");
    pair<sit, sit> ip = equal_range(v.begin(), v.end(), f);
    print<NString>(ip.first, ip.second, "equal_range");
    
    return 0;
} ///:~