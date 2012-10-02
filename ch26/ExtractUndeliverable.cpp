//: C26:ExtractUndeliverable.cpp
// Find undeliverable names to remove from
// mailing list from within a mail file
// containing many messages
#include <cstdio> // For fgets(), fputs(), FILE
#include <cstring> // For strstr(), strtok()
#include <string>
#include <set>

#include "../require.h"

using namespace std;

char* start_str[] = {
    "following address",
    "following recipient",
    "following destination",
    "undeliverable to the following",
    "following invalid",
};

char* continue_str[] = {
    "Message-ID",
    "Please reply to",
};

// The in() function allows you to check whether
// a string in this set is part of your argument.
class StringSet {
public:
    StringSet(char** sa, int sza) : ss(sa), sz(sza) {}

    bool in(char* s) {
        for (int i = 0; i < sz; i++) {
            if (0 != strstr(s, ss[i])) {
                return true;
            }
        }
        return false;
    }
private:
    char** ss;
    int sz;
};

// Calculate array length:
#define ALEN(A) ((sizeof(A))/(sizeof(*A)))

StringSet starts(start_str, ALEN(start_str));
StringSet continues(continue_str, ALEN(continue_str));

int main(int argc, char* argv[]) {
    if (3 != argc) {
        puts("Usage: ExtractUndeliverable infile outfile");
        return 0;
    }

    FILE* infile = fopen(argv[1], "rb");
    require(0 != infile);
    
    FILE* outfile = fopen(argv[2], "w");
    require(0 != outfile); //! 这里最好先关闭infile

    set<string> names;
    const int sz = 1024;
    char buf[sz];
    while (0 != fgets(buf, sz, infile)) {
        if (starts.in(buf)) {
            puts(buf);
            while (0 != fgets(buf, sz, infile)) {
                if (continues.in(buf)) {
                    continue;
                }
                if (0 != strstr(buf, "---")) {
                    break;
                }

                const char* delimiters = " \t<>():;,\n\"";
                char* name = strtok(buf, delimiters);
                while (0 != name) {
                    if (0 != strstr(name, "@")) {
                        names.insert(string(name));
                    }
                    name = strtok(0, delimiters);
                }
            }
        }
    }

    set<string>::iterator i =names.begin();
    while (i != names.end()) {
        fprintf(outfile, "%s\n", (*i++).c_str());
    }

    return 0;
} ///:~