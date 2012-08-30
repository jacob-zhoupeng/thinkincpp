//: C20:Stlshape2.cpp
// Stlshape2.cpp with the purge() function

#include <vector>
#include <iostream>

#include "../purge.h"

using namespace std;

class Shape {
public:
    virtual void draw() = 0;
    virtual ~Shape() {};
};

class Circle : public Shape {
public:
    void draw() {
        cout << "Circle::draw\n";
    }
    ~Circle() {
        cout << "~Circle\n";
    }
};

class Triangle : public Shape {
public:
    void draw() {
        cout << "Triangle::draw\n";
    }

    ~Triangle() {
        cout << "~Triangle\n";
    }
};

class Square : public Shape {
public:
    void draw() {
        cout << "Square::draw\n";
    }
    ~Square() {
        cout << "~Square\n";
    }
};

typedef std::vector<Shape*> Container;
typedef Container::iterator Iter;

int main(int argc, char* argv[]) {
    Container shapes;

    shapes.push_back(new Circle);
    shapes.push_back(new Square);
    shapes.push_back(new Triangle);

    for (Iter i = shapes.begin(); i != shapes.end(); i++) {
        (*i)->draw();
    }

    purge(shapes);

    return 0;
} ///:~