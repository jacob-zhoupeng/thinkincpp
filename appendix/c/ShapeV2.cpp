//: C:ShapeV2.cpp
// Alternative to ShapeV.cpp
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

    virtual void draw() = 0;

    virtual ~Shape() {
        cout << "~Shape\n";
    }

    static Shape* make(type);
protected:
    Shape() {} // Prevent stack objects
    // But allow access to derived constructors
private:
    Shape(Shape&); // No copy-construction
};

class Circle : public Shape {
public:
    void draw() {
        cout << "Circle::draw\n";
    }

    ~Circle() {
        cout << "~Circle\n";
    }

    friend Shape* Shape::make(type t);
protected:
    Circle() {}
private:
    Circle(Circle&); // No copy-construction
    Circle& operator=(Circle&); // No operator=
};


class Square : public Shape {
public:
    void draw() {
        cout << "Square::draw\n";
    }

    ~Square() {
        cout << "~Square\n";
    }

    friend Shape* Shape::make(type t);
protected:
    Square() {}
private:
    Square(Square&); // No copy-construction
    Square& operator=(Square&); // No operator=
};


class Triangle : public Shape {
public:
    void draw() {
        cout << "Triangle::draw\n";
    }

    ~Triangle() {
        cout << "~Triangle\n";
    }

    friend Shape* Shape::make(type t);
protected:
    Triangle() {}
private:
    Triangle(Triangle&); // No copy-construction
    Triangle& operator=(Triangle&); // Prevent
};

Shape* Shape::make(type t) {
    Shape* S;
    switch (t) {
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
    S->draw(); // Virtual function call
    return S;
}

// Acutally, use of auto ptr should be illegal?
template<class T>
class AutoVector : public vector<auto_ptr<T> > {
public:
    void add(T* p) {
        push_back(auto_ptr<T>(p));
    }
};

int main(int argc, char* argv[]) {
    AutoVector<Shape> shapes;

    cout << "virtual constructor calls:" << endl;
    shapes.add(Shape::make(Shape::tCircle));
    shapes.add(Shape::make(Shape::tSquare));
    shapes.add(Shape::make(Shape::tTriangle));

    cout << "virtual function calls:\n";
    for (int i = 0; i < shapes.size(); i++) {
        shapes[i]->draw();
    }

    //! Circle c; // Error: can't create on stack

    return 0;
} ///:~