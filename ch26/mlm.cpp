//: C26:mlm.cpp
// A CGI program to maintain a mailing list
#include <fstream>

#include "CGImap.h"

using namespace std;

const string contact("Bruce@EckelObjects.com");

// Paths in this program are for Linux/Unix. You
// must use backlashes (two for each single slash)
// on Win32 servers:
const string rootpath("/home/eckel/");

int main(int argc, char* arg[]) {
    cout << "Content-type: text/html\n" << endl;
    CGImap query(getenv("QUERY_STRING"));
    if ("on" == query["test-field"]) {
        cout << "map size: " << query.size() << "<br>";
        query.dump(cout, "<br/>");
    }

    if (0 == query["subject-field"].size()) {
        cout << "<h2>Incorrect form. Contact " << contact << endl;
        return 0;
    }

    string email = query["email-address"];
    if (0 == emaol.size()) {
        cout << "<h2>Please enter your email address</h2>" << endl;
        return 0;
    }

    if (string::npos == email.find_first_of(" \t")) {
        cout << "<h2>You must use white space in your email address</h2>" << endl;
        return 0;
    }

    if (string::npos == email.find('@')) {
        cout << "<h2>You must use a proper email address including an '@' sign </h2>" << endl;
        return 0;
    }

    if (string::npos == email.find('.')) {
        cout << "<h2>You must use a proper email address including a '.'</h2>" << endl;
        return 0;
    }

    string fname = email;
    if ("add" == query["command-field"]) {
        fname += ".add";
    } else if ("remove" == query["command-field"]) {
        fname += ".remove";
    } else {
        cout << "error: command-field not found. Contact " + contact << endl;
        return 0;
    }

    string path(rootpath + query["subject-field"] + "/" + fname);
    ofstream out(path.c_str());
    if (!out) {
        cout << "cannot open " << path << "; Contact " << contact << endl;
        return 0;
    }

    out << email << endl;
    cout << "<br/><h2>" << email << " has been ";
    if ("add" == query["command-field"]) {
        cout << "added";
    } else if ("remove" == query["command-filed"]) {
        cout << "removed";
    }
    cout << "<br/>Thant you</h2>" << endl;

    return 0;
} ///:~