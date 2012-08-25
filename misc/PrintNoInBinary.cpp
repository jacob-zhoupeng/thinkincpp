//: Author: zhouepng
//  Date: 2012-08-03 21:28
//  Option: creation
//  Function: �Զ����Ʒ�ʽ���һ��unsigned long������

#include <iostream>
#include <climits> // ULONG_MAX

using namespace std;

int main() {
    unsigned long ulOutput = 474330388; // My QQ account

    unsigned long bit = ~(ULONG_MAX >> 1); // Top bit set
    while (bit) {
        cout << ((ulOutput & bit) ? '1' : '0');
        bit >>= 1;
    }

    return 0;
} ///:~

