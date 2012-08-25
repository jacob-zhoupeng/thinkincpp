//: C03:Textchek.cpp
// Counts words and lines in a text file.
// Ensures no line is wider than maxwidth.
#include <iostream>
#include <cstring> // strlen() & strtok()

using namespace std;

int main() {
    // const means "you can't change it":
    const unsigned int maxwidth = 64;

    int linecount = 0;
    int wordcount = 0;

    char buf[100];
    char trash;

    while (cin.get(buf, 100) != '\0') {
        cin.get(trash); // Discard terminator
        linecount++; // We just read a whole line

        /**
         * 修改人：jacob.zhoupeng@gmail.com
         * 修改时间：2012-06-17 00:31
         *
         * 修改开始：
         * 修改原因：作者可能求行的长度时应该在调用strtok()函数之前，
         * 不然只会判断出是某行中的第一个单词长度大于MAXWIDTH，虽然结
         * 果一样，可是意思理解错误了。
         */
        if (strlen(buf) > maxwidth) {
            cout << "line " << linecount << " is too long." << endl;
        }
        /** 修改结束 */

        if (strtok(buf, " \t") != NULL) {
            wordcount++; // Count the first word
            /**
             * 这里调用strtok()后函数会记录下一个token开始位置，调用时用
             * NULL参数表示从下一个token开始位置开始分解单词。
             */
            while (strtok(NULL, " \t") != NULL) {
                wordcount++; // Count the rest
            }
        }

        /**
         * 这里的判断被提前了。
        if (strlen(buf) > maxwidth) {
            cout << "line " << linecount << " is too long." << endl;
        }
        */
    }

    cout << "lines: " << linecount << endl;
    cout << "Words: " << wordcount << endl;

    return 0;
} ///:~
