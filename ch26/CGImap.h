//: C26:CGImap.h
// Tools for extracting and decoding data from
// CGI GETs and POSTs.
#ifndef CGIMAP_H
#define CGIMAP_H

#include <cstdlib> // For getenv() & atoi()
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class CGIpair : public pair<string, string> {
public:
    CGIpair() {}

    CGIpair(string name, string value) {
        first = decodeURLString(name);
        second = decodeURLString(value);
    }

    // Automatically type conversion for boolean test:
    operator bool() const {
        return (0 != first.length());
    }
private:
    static string decodeURLString(string URLstr) {
        const int len = URLstr.length();
        string result;
        for (int i = 0; i < len; i++) {
            if ('+' == URLstr[i]) {
                result += ' ';
            } else if ('%' == URLstr[i]) {
                result += translateHex(URLstr[i+1]) * 16 + 
                    translateHex(URLstr[i+2]);
                i += 2; // Move past hex code
            } else { // An ordinary character
                result += URLstr[i];
            }
        }
        return result;
    }

    // Translate a single hex character; used by
    // decodeURLString():
    static char translateHex(char hex) {
        if (hex >= 'A') {
            return (hex & 0xdf) - 'A' + 10;
        } else {
            return hex - '0';
        }
    }
};

// Parses an CGI query and turns it into an
// STL vector of CGIpair which has an associative
// lookup operator[] like a map. A vector is used
// instead of a map because it keeps the original
// ordering of the fields in the Web page form.
class CGImap : public vector<CGIpair> {
public:
    CGImap(string query) : index(0), gq(query) {
        CGIpair p;
        while ((p = nextPair()) != 0) {
            push_back(p);
        }
    }

    // Look something up, as if it were a map:
    string operator[](const string& key) {
        iterator i = begin();
        while (i != end()) {
            if (key == (*i).first) {
                return (*i).second;
            }
            i++;
        }
        return string(); // Empty string == not found
    }

    void dump(ostream& o, string nl = "<br/>") {
        for (iterator i = begin(); i != end(); i++) {
            o << (*i).first << " = " << (*i).second << nl;
        }
    }
private:
    string gq;
    int index;
    
    // Prevent assignment and copy-construction:
    CGImap& operator=(CGImap&);
    CGImap(CGImap&);

    // Produces name-value pairs from the query
    // string. Returns an empty Pair when there's
    // no more query string left:
    CGIpair nextPair() {
        if (0 == gq.length()) {
            return CGIpair(); // Error, return empty
        }
        
        if (string::npos == gq.find('=')) {
            return CGIpair(); // Error, return empty
        }

        string name = gq.substr(0, gq.find('='));
        gq = gq.substr(gq.find('=') + 1);
        string value = gq.substr(0, gq.find('&'));
        gq = gq.substr(gq.find('&') + 1);

        return CGIpair(name, value);
    }
};

// Helper class for getting POST data:
class Post : public string {
public:
    Post() {
        // For a CGI "POST," the server puts the
        // length of the content string in the
        // environment variable CONTENT_LENGTH:
        char* clen = getenv("CONTENT_LENGTH");
        if (0 == clen) {
            cout << "Zero CONTENT_LENGTH, Make sure "
                "this is a POST and not a GET" << endl;
            return;
        }

        int len = atoi(clen);
        char* s = new char[len];
        cin.read(s, len); // Get the data
        append(s, len); // Add it to this string
        delete s;
    }
};

#endif // CGIMAP_H ///:~