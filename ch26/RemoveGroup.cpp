//: C26:RemoveGroup.cpp
// Remove a group of names from a list
#include <list>

#include "readLower.h"
#include "../require.h"

using namespace std;

typedef list<string> Container;

int main(int argc, char* argv[]) {
    requireArgs(argc, 4);

    Container names;
    Container removals;

    readLower(argv[1], names);
    readLower(argv[2], removals);

    long original = names.size();
    Container::iterator rmit = removals.begin();
    while (rmit != removals.end()) {
        names.remove(*rmit++); // Removes all matches
    }

    ofstream out(argv[3]);
    assure(out, argv[3]);

    copy(names.begin(), names.end(), ostream_iterator<string>(out, "\n"));
    long removed = original - names.size();
    cout << "On removal list: " << removals.size() << endl
         << "Removed: " << removed << endl;

    return 0;
} ///:~