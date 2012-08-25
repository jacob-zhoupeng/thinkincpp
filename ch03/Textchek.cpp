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
         * �޸��ˣ�jacob.zhoupeng@gmail.com
         * �޸�ʱ�䣺2012-06-17 00:31
         *
         * �޸Ŀ�ʼ��
         * �޸�ԭ�����߿������еĳ���ʱӦ���ڵ���strtok()����֮ǰ��
         * ��Ȼֻ���жϳ���ĳ���еĵ�һ�����ʳ��ȴ���MAXWIDTH����Ȼ��
         * ��һ����������˼�������ˡ�
         */
        if (strlen(buf) > maxwidth) {
            cout << "line " << linecount << " is too long." << endl;
        }
        /** �޸Ľ��� */

        if (strtok(buf, " \t") != NULL) {
            wordcount++; // Count the first word
            /**
             * �������strtok()�������¼��һ��token��ʼλ�ã�����ʱ��
             * NULL������ʾ����һ��token��ʼλ�ÿ�ʼ�ֽⵥ�ʡ�
             */
            while (strtok(NULL, " \t") != NULL) {
                wordcount++; // Count the rest
            }
        }

        /**
         * ������жϱ���ǰ�ˡ�
        if (strlen(buf) > maxwidth) {
            cout << "line " << linecount << " is too long." << endl;
        }
        */
    }

    cout << "lines: " << linecount << endl;
    cout << "Words: " << wordcount << endl;

    return 0;
} ///:~
