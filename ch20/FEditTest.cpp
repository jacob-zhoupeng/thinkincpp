//: C20:FEditTest.cpp
// {L} FileEditor
// Test the FileEditor tool

#include <sstream>

#include "FileEditor.h"

using namespace std;

int main(int argc, char* argv[]) {
    FileEditor file(argv[1]);

    // Do something to the lines...
    int i = 1;
    FileEditor::iterator w = file.begin();
    while (w != file.end()) {
        ostringstream ss;
        ss << i++;
        *w = ss.str() + ": " + *w;
        w++;
    }

    // Now send them to cout:
    file.write();

    return 0;
} ///:~

