//: C20:Stlshape.cpp
// Simple shapes w/ STL

#include <vector>
#include <iostream>

using namespace std;

class shape {
public:
    virtual void draw() = 0;
    virtual ~shape() {};
};

class circle : public shape {
public:
    void draw() {
        cout << "circle::draw\n";
    }

    ~circle() {
        cout << "~circle\n";
    }
};

class triangle : public shape {
public:
    void draw() {
        cout << "triangle::draw\n";
    }
    ~triangle() {
        cout << "~triangle\n";
    }
};

class square : public shape {
public:
    void draw() {
        cout << "square::draw\n";
    }
    ~square() {
        cout << "~square\n";
    }
};

typedef std::vector<shape*> container;

typedef container::iterator iter;

int main() {
    container shapes;

    shapes.push_back(new circle);
    shapes.push_back(new square);
    shapes.push_back(new triangle);
    
    for (iter i = shapes.begin(); i != shapes.end(); i++) {
        (*i)->draw();
    }

    // ... Sometime later:
    for (iter i = shapes.begin(); i != shapes.end(); i++) {
        delete (*i);
    }

    return 0;
} ///:~

