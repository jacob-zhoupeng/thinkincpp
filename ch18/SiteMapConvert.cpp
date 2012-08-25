//: C18:SiteMapConvert.cpp
// Using strings to create a custom conversion
// program that generates HTML output

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cassert>
#include <string>

using namespace std;

class Item {
public:
    Item(string in, int& index) : depth(0) {
        while (in[index] == '#' && index < in.size()) {
            depth++;
            index++;
        }
        // 0 means no '#' marks were found:
        if (depth == 0) {
            depth = 1;
        }
        while (in[index] != '%' && index < in.size()) {
            id += in[index++];
        }
        id = removeBar(id);
        index++; // Move past '%'
        while (in[index] != '*' && index < in.size()) {
            url += in[index++];
        }
        url = removeBar(url);
        index++; // To move past '*'
    }

    string identifier() {
        return id;
    }

    string path() {
        return url;
    }

    int level() {
        return depth;
    }
private:
    string id;
    string url;
    int depth;
    string removeBar(string s) {
        if (s[0] == '|') {
            return s.substr(1);
        } else {
            return s;
        }
    }
};

int main(int argc, char **argv) {
    if (argc < 1) {
        cerr << "usage: " << argv[0]
             << " inputfilename" << endl;
        exit(1);
    }
    ifstream in(argv[1]);
    assert(in);
    ofstream out("plainmap.html");
    string line;
    while (getline(in, line)) {
        if (line.find("<param name=\"source_file\"") != string::npos) {
            // Extract data of from start of sequence
            // until the terminating quote mark:
            line = line.substr(line.find("value=\"")
                               + string("value=\"").size());
            line = line.substr(0, line.find_last_of("\""));
            int index = 0;
            while (index < line.size()) {
                Item item(line, index);
                string startLevel, endLevel;
                if (item.level() == 1) {
                    startLevel = "<h1>";
                    endLevel = "</h1>";
                } else {
                    for (int i = 0; i < item.level(); i++) {
                        for (int j = 0; j < 5; j++) {
                            out << "&nbsp;";
                        }
                    }
                    string htmlLine = "<a href=\""
                                      + item.path() + "\">"
                                      + item.identifier() + "</a><br/>";
                    out << startLevel << htmlLine << endLevel << endl;
                }
                break; // Out of the loop
            }
        }
    }
}
