//: C:ShapeV.cpp
// "Virtual constructors"
// Used in a simple "Shape" fromework
#include <iostream>
#include <vector>

using namespace std;

class Shape {
public:
    enum type {
        tCircle,
        tSquare,
        tTriangle
    };
    
    Shape(type); // "Virtual" constructor

    virtual void draw() {
        S->draw();
    }

    virtual ~Shape() {
        cout << "~Shape\n";
        delete S;
    }
protected:
    Shape() {
        S = 0;
    }
private:
    Shape* S;

    // Prevent copy-constructor & operator=
    Shape(Shape&);
    Shape& operator=(Shape&);
};


class Circle : public Shape {
public:
    Circle() {}

    void draw() {
        cout << "Circle::draw\n";
    }

    ~Circle() {
        cout << "~Circle\n";
    }
private:
    Circle(Circle&);
    Circle& operator=(Circle&);
};


class Square : public Shape {
public:
    Square() {}

    void draw() {
        cout << "Square::draw\n";
    }

    ~Square() {
        cout << "~Square\n";
    }
private:
    Square(Square&);
    Square& operator=(Square&);
};


class Triangle : public Shape {
public:
    Triangle() {}

    void draw() {
        cout << "Triangle::draw\n";
    }

    ~Triangle() {
        cout << "~Triangle\n";
    }
private:
    Triangle(Square&);
    Triangle& operator=(Triangle&);
};

Shape::Shape(type t) {
    switch(t) {
        case tCircle: 
            S = new Circle;
            break;
        case tSquare:
            S = new Square;
            break;
        case tTriangle:
            S = new Triangle;
            break;
    }
    draw(); // Virtual call in the constructor
}

// Actually, use of auto_ptr should be illegal?
template<class T>
class AutoVector : public vector<auto_ptr<T> > {
public:
    void add(T* p) {
        push_back(auto_ptr<T>(p));
    }
};

int main(int argc, char* argv[]) {
    AutoVector<Shape> Shapes;
    
    cout << "virtual constructor calls:" << endl;
    Shapes.add(new Shape(Shape::tCircle));
    Shapes.add(new Shape(Shape::tSquare));
    Shapes.add(new Shape(Shape::tTriangle));

    cout << "virtual function calls:" << endl;
    for (int i = 0; i < Shapes.size(); i++) {
        Shapes[i]->draw();
    }

    Shape c(Shape::tCircle); // Can create on stack

    return 0;
} ///:~