//: C21:SortTest.cpp
// {L} ../ch20/StreamTokenizer
// Test different kinds of sorting

#include <algorithm>
#include <fstream>
#include <queue>
#include <vector>
#include <string>
#include <cctype>

#include "../require.h"
#include "../ch20/StreamTokenizer.h"

#include "NString.h"
#include "PrintSequence.h"
#include "Generators.h"

using namespace std;

// For sorting NStrings and ignore string case:
struct NoCase {
    bool operator()(const NString& x, const NString& y) {
        /**
         * Somthing's wrong with this approach but I can't seem to see it.
         * It would be much faster:
         *
         *     const string& lv = x;
         *     const string& rv = y;
         *     int len = min(lv.size(), rv.size());
         *     for (int i = 0; i < len; i++) {
         *         if (tolower(lv[i]) < tolower(rv[i])) {
         *             return true;
         *         }
         *     }
         *     return false;
         * }
         */
         // Brute force: copy, force to lowercase:
         string lv(x);
         string rv(y);

         lcase(lv);
         lcase(rv);

         return lv < rv;
    }

    void lcase(string& s) {
        int n = s.size();
        for (int i = 0; i < n; i++) {
            s[i] = tolower(s[i]);
        }
    }
};

int main(int argc, char* argv[]) {
    requireArgs(argc, 2);
    ifstream in(argv[1]);
    assure(in, argv[1]);

    StreamTokenizer words(in);
    deque<NString> nstr;
    string word;
    while ((word = words.next()).size() != 0) {
        nstr.push_back(NString(word));
    }
    print<NString>(nstr);

    // Create a vector from the contents of nstr:
    vector<NString> v(nstr.begin(), nstr.end());

    sort(v.begin(), v.end());
    print<NString>(v, "sort");

    // Use an additional comparator object:
    sort(v.begin(), v.end(), NoCase());
    print<NString>(v, "sort NoCase");

    copy(nstr.begin(), nstr.end(), v.begin());

    stable_sort(v.begin(), v.end());
    print<NString>(v, "stable_sort");

    // Use an additional comparater object:
    stable_sort(v.begin(), v.end(), greater<NString>());
    print<NString>(v, "stable_sort greater");

    copy(nstr.begin(), nstr.end(), v.begin());

    // Partial sorts. The additional comparator
    // version are abvious and not shown here.
    partial_sort(v.begin(), v.begin() + v.size()/2, v.end());
    print<NString>(v, "parial_sort");

    // Create a vector with a preallocated size:
    vector<NString> v2(v.size()/2);

    partial_sort_copy(v.begin(), v.end(), v2.begin(), v2.end());
    print<NString>(v2, "partial_sort_copy");

    // Finally, the weakest form of ordering:
    vector<int> v3(20);
    generate(v3.begin(), v3.end(), URandGen(50));
    print<int>(v3, "v3 before nth_element");

    int n = 10;
    vector<int>::iterator vit = v3.begin() + n;
    nth_element(v3.begin(), vit, v3.end());
    cout << "After ordering with nth = " << n 
        << ", nth element is " << v3[n] << endl;
    print<int>(v3, "v3 after nth_element");

    return 0;
} ///:~
