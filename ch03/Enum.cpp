//: C03:Enum.cpp
// Keeping track of shapes.

enum shape_type {
    circle,
    square,
    rectangle
}; // Must end with a semicolon like a class

int main() {
    shape_type shape = circle;
    // Activities here....
    // Now do something based on what the shape is:
    switch (shape) {
    case circle:
        /* circle stuff */
        break;
    case square:
        /* square stuff */
        break;
    case rectangle:
        /* rectangle stuff */
        break;
    }

    return 0;
} ///:~
