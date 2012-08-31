//: C20:StreamTokenizer.h
// C++ Replacement for Standard C strtok()
#ifndef STREAMTOKENIZR_H_
#define STREAMTOKENIZR_H_

#include <string>
#include <iostream>
#include <iterator>

class StreamTokenizer {
public:
    StreamTokenizer(std::istream& is, 
            std::string delim = " \t\n;()\"<>:{}[]+-=&*#.,/\\~!0123456789") 
            : p(is), end(It()), delimiters(delim) {}
    std::string next(); // Get next token
private:
    typedef std::istreambuf_iterator<char> It;
    It p;
    It end;
    std::string delimiters;
    
    bool isDelimiter(char c) {
        return delimiters.find(c) != std::string::npos;
    }
};

#endif // STREAMTOKENIZR_H_ ///:~

