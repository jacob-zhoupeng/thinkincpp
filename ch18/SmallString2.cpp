//: C18:SmallString2.cpp

#include <string>

using namespace std;

int main(int argc, char *argv[]) {
    string s1("What is the sound of one clam napping?");
    string s2("Anything worth doing is worth overdoing.");
    string s3("I saw Elvis in a URF.");

    // Copy the first 8 chars
    string s4(s1, 0, 8);

    // Copy 6 chars from the middle of the source
    string s5(s2, 15, 6);

    // Copy from middle to end
    string s6(s3, 6, 15);

    // Copy all sorts of stuff
    string quoteMe = s4 + " that" +

    // substr() copies up to either 100 char
    // or eos starting at element 5
    " with" + s3.substr(5, 100) +

    // OK to copy a single char this way
    s1.substr(37, 1);

    return 0;
} ///:~
