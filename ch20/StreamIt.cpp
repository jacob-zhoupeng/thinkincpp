//: C20:StreamIt.cpp
// Iterators for istreams and ostreams

#include <iostream>
#include <fstream>
#include <string>
#include <iterator>
#include <vector>

#include "../require.h"

using namespace std;

int main() {
    ifstream in("StreamIt.cpp");
    require(in, "StreamIt.cpp");

    istream_iterator<string> init(in);
    istream_iterator<string> end;
    ostream_iterator<string> out(cout, "\n");
    vector<string> vs;

    copy(init, end, back_inserter(vs));
    copy(vs.begin(), vs.end(), out);
    out = vs[0];
    out = "That's all, folks!";

    return 0;
} ///:~

