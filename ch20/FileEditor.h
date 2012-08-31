//: C20:FileEditor.h
// File editor tool
#ifndef FILEEDITOR_H_
#define FILEEDITOR_H_

#include <string>
#include <vector>
#include <iostream>

class FileEditor : public std::vector<std::string> {
public:
    FileEditor(char* filename);
    void write(std::ostream& out = std::cout);
};

#endif // FILEEDITOR_H_

