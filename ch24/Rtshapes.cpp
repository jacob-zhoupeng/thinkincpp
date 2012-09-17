//: C24:Rtshapes.cpp
// Counting shapes
#include <iostream>
#include <ctime>
#include <typeinfo>
#include <vector>

#include "../purge.h"

using namespace std;

class Shape {
public:
    Shape() {
        count++;
    }

    virtual ~Shape() {
        count--;
    }

    virtual void draw() const = 0;

    static int quantity() {
        return count;
    }
protected:
    static int count;
};

int Shape::count = 0;

class SRectangle : public Shape {
public:
    SRectangle() {
        count++;
    }

    SRectangle(const SRectangle&) {
        count++;
    }

    ~SRectangle() {
        count--;
    }

    void draw() const {
        cout << "SRectangle::draw()" << endl;
    }

    static int quantity() {
        return count;
    }
protected:
    static int count;
private:
    SRectangle& operator=(SRectangle&); // Disallow
};

int SRectangle::count = 0;

class SEllipse : public Shape {
public:
    SEllipse() {
        count++;
    }

    SEllipse(const SEllipse&) {
        count++;
    }

    ~SEllipse() {
        count--;
    }

    void draw() const {
        cout << "SEllipse::draw()" << endl;
    }

    static int quantity() {
        return count;
    }
protected:
    static int count;
private:
    SEllipse& operator=(SEllipse&); // Disallow
};

int SEllipse::count = 0;

class SCircle : public SEllipse {
public:
    SCircle() {
        count++;
    }

    SCircle(const SCircle&) {
        count++;
    }

    ~SCircle() {
        count--;
    }

    void draw() const {
        cout << "SCircle::draw()" << endl;
    }

    static int quantity() {
        return count;
    }    
protected:
    static int count;
private:
    SCircle& operator=(SCircle&); // Disallow
};

int SCircle::count = 0;

int main(int argc, char* argv[]) {
    vector<Shape*> shapes;
    srand(time(0)); // Seed random number generator
    const int mod = 12;

    // Create a random quantity of each type:
    for (int i = 0; i < rand() % mod; i++) {
        shapes.push_back(new SRectangle);
    }

    for (int j = 0; j < rand() % mod; j++) {
        shapes.push_back(new SCircle);
    }

    for (int k = 0; k < rand() % mod; k++) {
        shapes.push_back(new SCircle);
    }

    int Ncircles = 0;
    int Nellipses = 0;
    int Nrects = 0;
    int Nshapes = 0;

    for (int u = 0; u < shapes.size(); u++) {
        shapes[u]->draw();
        if (dynamic_cast<SCircle*>(shapes[u])) {
            Ncircles++;
        }

        if (dynamic_cast<SEllipse*>(shapes[u])) {
            Nellipses++;
        }

        if (dynamic_cast<SRectangle*>(shapes[u])) {
            Nrects++;
        }

        if (dynamic_cast<Shape*>(shapes[u])) {
            Nshapes++;
        }
    }

    cout << endl << endl
        << "Circles = " << Ncircles << endl
        << "Ellipses = " << Nellipses << endl
        << "Rectangles = " << Nrects << endl
        << "Shapes = " << Nshapes << endl 
        << endl
        << "SCircle::quantity() = " << SCircle::quantity() << endl
        << "SEllipse::quantity() = " << SEllipse::quantity() << endl
        << "SRectangle::quantity() = " << SRectangle::quantity() << endl
        << "Shape::quantity() = " << Shape::quantity() << endl;

    purge(shapes);

    return 0;
} ///:~