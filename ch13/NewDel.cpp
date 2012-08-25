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
    //! 重载操作符'<<': ostream << Tree
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

    t = NULL; //! C/C++在free和delete对象后，最佳实践是将指针
              //!设为NULL，防止二次释放内存，引起严重错误！

    return 0;
} ///:~
