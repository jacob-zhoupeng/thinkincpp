//: C06:Constrl.cpp
// Constructors & destructors

#include <cstdio>

using namespace std;

class Tree {
public:
    Tree(int initialHeight); // Constructor
    ~Tree(); // Destructor
    void grow(int years);
    void printsize();
private:
    int height;
};

Tree::Tree(int initialHeight) {
    height = initialHeight;
}

Tree::~Tree() {
    puts("inside Tree destructor");
    printsize();
}

void Tree::grow(int years) {
    height += years;
}

void Tree::printsize() {
    printf("Tree height is %d\n", height);
}

int main() {
    puts("before opening brace");
    {
        Tree t(12);
        puts("after Tree creation");
        t.printsize();
        t.grow(4);
        puts("before closing brace");
    }
    puts("after closing brace");

    return 0;
} ///:~
