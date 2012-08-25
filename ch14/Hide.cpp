//: C14:Hide.cpp
// Name hiding during inheritance

class Homer {
public:
    int doh(int) const {
        return 1;
    }
    char doh(char) const {
        return 'd';
    }
    float doh(float) const {
        return 1.0;
    }
};

class Bart : public Homer {
public:
    class Milhouse {};
    //! 子类的同名函数将会隐藏父类所有的
    //! 同名(public，overloaded)函数
    void doh(Milhouse) const {}
};

int main() {
    Bart b;

    //! b.doh(1); // Error
    //! b.doh('x'); // Error
    //! b.doh(1.0f); // Error

    return 0;
} ///:~
