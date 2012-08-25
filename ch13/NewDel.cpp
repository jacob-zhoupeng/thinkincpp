//: C13:NewDel.cpp
// Simple demo of new & delete

#include <iostream>

using namespace std;

class Tree {
public:
    Tree(int Height) {
        height = Height;
    }
    ~Tree() {
        cout << "*";
    }
    //! ���ز�����'<<': ostream << Tree
    friend ostream &operator<<(ostream &os, const Tree *t) {
        return os << "Tree height is: " << t->height << endl;
    }
private:
    int height;
};

int main() {
    Tree *t = new Tree(40);

    cout << t; //! This can prove the constructor has been called
    delete t; //! This can prove the destructor has been called

    t = NULL; //! C/C++��free��delete��������ʵ���ǽ�ָ��
              //!��ΪNULL����ֹ�����ͷ��ڴ棬�������ش���

    return 0;
} ///:~
