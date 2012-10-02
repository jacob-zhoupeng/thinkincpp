//: C26:DataToSpreadsheet.cpp
// {L} FormData
#include <cstdio>
#include <string>

#include "FormData.h"
#include "../require.h"

using namespace std;

string delimiter("\t");

int main(int argc, char* argv[]) {
    for (int i = 1; i < argc; i++) {
        FormData fd(argv[i]);
        cout << fd.email << delimiter;
        for (FormData::iterator i = fd.begin(); i != fd.end(); i++) {
            if ("workshop-suggestions" != (*i).first) {
                cout << (*i).second << delimiter;
            }
        }
        cout << endl;
    }

    return 0;
} ///:~