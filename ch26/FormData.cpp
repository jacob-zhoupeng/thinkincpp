//: C26:FormData.cpp {O}
#include <cstring>

#include "FormData.h"
#include "../require.h"

DataPair& DataPair::get(istream& in) {
    first.erase();
    second.erase();

    string ln;
    getline(in, ln);
    while (string::npos == ln.find("[{[")) {
        if (!getline(in, ln)) {
            return *this; // End
        }
    }
    first = ln.substr(3, ln.find("]}]") - 3);

    getline(in, ln); // Throw away [([
    while (getline(in, ln)) {
        if (string::npos == ln.find("])]")) {
            second += ln + string(" ");
        } else {
            return *this;
        }
    }
}

FormData::FormData(char * fileName) {
    ifstream in(fileName);
    assure(in, fileName);
    require(0 != getline(in, filePath));

    // Should be start of first line:
    require(0 == filePath.find("///{"));
    filePath = filePath.substr(std::strlen("///{"));
    require(0 != getline(in, email));

    // Should be start of 2nd line:
    require(0 == email.find("From["));
    int begin = strlen("From[");
    int end = email.find("]");
    int length = end - begin;
    email = email.substr(begin, length);

    // Get the rest of the data:
    DataPair dp(in);
    while (dp) {
        push_back(dp);
        dp.get(in);
    }
}

string FormData::operator[](const string& key) {
    iterator i = begin();
    while (i != end()) {
        if (key == (*i).first) {
            return (*i).second;
        }
        i++;
    }
    return string(); // Empty string == not found
}

void FormData::dump(ostream& os) {
    os << "filePath = " << filePath << endl;
    os << "email = " << email << endl;

    for (iterator i = begin(); i != end(); i++) {
        os << (*i).first << " = " << (*i).second << endl;
    }
}