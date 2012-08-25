//: C09:Rectangl.cpp
// Accessor & mutators

class Rectangle {
public:
    Rectangle(int W = 0, int H = 0) : Width(W), Height (H) {
        // Empty body
    }
    int width() const { // Read
        return Width;
    }
    void width(int W) { // Set
        Width = W;
    }
    int height() const { // Read
        return Height;
    }
    void height(int H) { // Set
        Height = H;
    }
private:
    int Width;
    int Height;
};

int main() {
    Rectangle R(19, 47);

    // Change width & height:
    R.height(2 * R.width());
    R.width(2 * R.width());

    return 0;
} ///:~
