//: C18:ReprocessHTML.cpp
// Take Word's html output and fix up
// The code listing and html tags

#include <iostream>
#include <fstream>
#include <cassert>
#include <fstream>
#include <cstring>

using namespace std;

// Produce a new string which is the original
// string with the html paragraph break marks
// stripped off:
string stripPBreaks(string s) {
    unsigned int br;
    while ((br = s.find("<p>")) != string::npos) {
        s.erase(br, strlen("<p>"));
    }
    while ((br = s.find("</p>"))) {
        s.erase(br, strlen("</p>"));
    }
    return s;
}

// After the beginning of a code listing is
// detected, this function cleans up the listing
// until the end marker is found. The first line
// of the listing is passed in by the caller,
// which detects the start marker in the line.
void fixupCodeListing(istream& in, ostream& out,
                      string& line, int tag) {
    out << line.substr(0, tag) << "<PRE>" // Means "preformtted" in html
        << stripPBreaks(line.substr(tag)) << endl;
    string s;
    while (NULL != getline(in, s)) {
        unsigned int endtag = s.find("/""/""/"":~");
        if (endtag != string::npos) {
            endtag += strlen("/""/""/"":~");
            string before = s.substr(0, endtag);
            string after = s.substr(endtag);
            out << stripPBreaks(before) << "</PRE>"
                << after << endl;
            return;
        }
        out << stripPBreaks(s) << endl;
    }
}

string removals[] {
    "<FONT SIZE=2>",
    "<FONT SIZE=1>",
    "<FONT FACE=\"Times\" SIZE=1>",
    "<FONT FACE=\"Times\" SIZE=2>",
    "<FONT FACE=\"Courier\" SIZE=1>",
    "SIZE=1", // Eliminate all other '1' & '2' size
    "SIZE=2",
};

const int rmsz = sizeof(removals) / sizeof(*removals); // removals类似C语言的指针数组？？？

int main(int argc, char *argv[]) {
    assert(argc == 3);
    ifstream in(argv[1]);
    assert(in);
    ofstream out(argv[2]);

    string line;
    while (getline(in, line)) {
        // The "Body" tag only appears once:
        if (line.find("<BODY>=") != string::npos) {
            out << "<BODY BGCOLOR=\"#FFFFFF\" "
            "TEXT=\"#000000\">" << endl;
            continue; // Get next line
        }

        // Eliminate each of the removals strings:
        for (int i = 0; i < rmsz; i++) {
            unsigned int find = line.find(removals[i]);
            if (find != string::npos) {
                line.erase(find, removals[i].size());
            }

            unsigned int tag1 = line.find("/""/"":");
            unsigned int tag2 = line.find("/""*"":");

            if (tag1 != string::npos) {
                fixupCodeListing(in, out, line, tag1);
            } else if (tag2 != string::npos) {
                fixupCodeListing(in, out, line, tag2);
            } else {
                out << line << endl;
            }
        }
    }

    return 0;
} ///:~
