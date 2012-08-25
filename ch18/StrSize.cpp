//: C18:StrSize.cpp

#include <string>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    string bigNews("I saw Elvis in a UFO. ");
    cout << bigNews << endl;
    // How much data have we actually got?
    cout << "Size = " << bigNews.size() << endl;
    // How much can we store without reallocating
    cout << "Capacity = " << bigNews.capacity() << endl;

    // Insert this string in bigNews immediately
    // following bigNews[1]
    bigNews.insert(1, " thought I "); //! 这会导致capacity按一定实现增加。
    cout << bigNews << endl;
    cout << "Size = " << bigNews.size() << endl;
    cout << "Capacity = " << bigNews.capacity() << endl;

    // Make sure that there will be this much space
    bigNews.reserve(500);

    // Add this to the end of the string
    bigNews.append("I've been working too hard.");
    cout << bigNews << endl;
    cout << "Size = " << bigNews.size() << endl;
    cout << "Capacity = " << bigNews.capacity() << endl;

    return 0;
} ///:~
