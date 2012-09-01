//: C21:Manipulations.cpp
// Shows basic manipulations

#include <vector>
#include <string>
#include <algorithm>
#include <cstring>

#include "Generators.h"
#include "PrintSequence.h"
#include "NString.h"

using namespace std;

int main(int argc, char* argv[]) {
    vector<int> v1(10);

    // Simple counting:
    generate(v1.begin(), v1.end(), SkipGen());
    print<int>(v1, "v1", " ");
    
    vector<int> v2(v1.size());
    copy_backward(v1.begin(), v1.end(), v2.end());
    print<int>(v2, "copy_backward", " ");

    reverse_copy(v1.begin(), v1.end(), v2.begin());
    print<int>(v2, "reverse_copy", " ");

    reverse(v1.begin(), v1.end());
    print<int>(v1, "reverse", " ");

    int half = v1.size() / 2;

    // Ranges must be exactly the same size:
    swap_ranges(v1.begin(), v1.begin() + half, v1.begin() + half);
    print<int>(v1, "swap_ranges", " ");

    // Start with fresh sequence:
    generate(v1.begin(), v1.end(), SkipGen());
    print<int>(v1, "v1", " ");
    
    int third = v1.size() / 3;

    for (int i = 0; i < 10; i++) {
        rotate(v1.begin(), v1.begin() + third, v1.end());
        print<int>(v1, "rotate", " ");
    }

    cout << "Second rotate example:" << endl;

    char c[] = "aabbccddeeffgghhiijj";
    const char csz = strlen(c);

    for (int i = 0; i < 10; i++) {
        rotate(c, c + 2, c + csz);
        print<char>(c, c + csz, "", "");
    }

    cout << "All n! permutations of abcd:" << endl;
    int nf = 4 * 3 * 2 * 1;
    char p[] = "abcd";
    for (int i = 0; i < nf; i++) {
        next_permutation(p, p + 4);
        print<char>(p, p + 4, "", "");
    }
    
    cout << "Using prev_permuations:" << endl;
    for (int i = 0; i < nf; i++) {
        prev_permutation(p, p + 4);
        print<char>(p, p + 4, "", "");
    }

    cout << "random_shuffling a word:" << endl;
    string s("hello");
    cout << s << endl;

    for (int i = 0; i < 5; i++) {
        random_shuffle(s.begin(), s.end());
        cout << s << endl;
    }

    NString sa[] = { "a", "b", "c", "d", "a", "b", "c", "d", 
        "a", "b", "c", "d", "a", "b", "c" };
    const int sasz = sizeof(sa)/sizeof(*sa);

    vector<NString> ns(sa, sa + sasz);
    print<NString>(ns, "ns", " ");
    vector<NString>::iterator it = partition(ns.begin(), ns.end(), 
        bind2nd(greater<NString>(), "b"));
    cout << "Partition point: " << *it << endl;
    print<NString>(ns, "", " ");

    // Reload vector:
    copy(sa, sa + sasz, ns.begin());
    it = stable_partition(ns.begin(), ns.end(), 
        bind2nd(greater<NString>(), "b"));
    cout << "Stable partition" << endl;
    cout << "Partition point: " << *it << endl;
    print<NString>(ns, "", " ");

    return 0;
} ///:~