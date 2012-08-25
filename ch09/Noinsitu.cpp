//: C09:Noinsitu.cpp
// Removing in situ functions

class Rectangle {
public:
    Rectangle(int W = 0, int H = 0);
    int width() const; // Read
    void width(int W); // Set
    int height() const; // Read
    void height(int H); // Set
private:
    int Width;
    int Height;
};

inline Rectangle::Rectangle(int W, int H) : Width(W), Height(H) {
    // Empty body
}

inline int Rectangle::width() const {
    return Width;
}

inline void Rectangle::width(int W) {
    Width = W;
}

inline int Rectangle::height() const {
    return Height;
}

inline void Rectangle::height(int H) {
    Height = H;
}

int main() {
    Rectangle R(19, 47);

    // Transpose width & height
    R.height(R.width());
    R.width(R.height());

    return 0;
} ///:~
