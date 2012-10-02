//: C26:RemoveDuplicates.cpp
// Remove duplicate names from a mailing list
#include <vector>

#include "../require.h"
#include "readLower.h"

using namespace std;

int main(int argc, char* arg[]) {
    requireArgs(argc, 3);

    vector<string> names;
    readLower(argv[1], names);
    long before = names.size();

    // You must sort first for unique() to work:
    sort(names.begin(), names.end());

    // Remove adjacent duplicates:
    unique(names.begin(), names.end());

    long removed = before - names.size();
    ofstream out(argv[2]);
    assure(out, argv[2]);
    copy(names.begin(), names.end(), ostream_iterator<string>(cout, "\n"));
    cout << removed << " names removed" << endl;

    return 0;
} ///:~