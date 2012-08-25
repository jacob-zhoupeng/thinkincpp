//: C12:FeeFi2.cpp
// Copying vs. initialization

class Fi {
    // Empty class
};

class Fee {
public:
    Fee(int){
        // Empty body
    }
    Fee(const Fee &){
        // Empty body
    }
};

class Fo {
public:
    Fo(int x = 0) {
        i = x;
    }
    operator Fee() const  {
        return Fee(i);
    }
private:
    int i;
};

int main() {
    Fo fo;
    Fee fiddle = fo; //! 先调用Fo类的重载函数将fo转换成
                     //! Fee对象，然后调用Fee类的复制构造函数

    return 0;
} ///:~
