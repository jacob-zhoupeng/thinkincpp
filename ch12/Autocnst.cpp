//: C12:Autocnst.cpp
// Type conversion constructor

class One {
public:
    One() {
        // Empty body
    }
};

class Two {
public:
    //! 添加explicit关键字可以强制编译器要求显示转换参数
    /* explicit */ Two(const One &) {
        // Empty body
    }
};

void f(Two) {
    // Empty body
}

int main() {
    One one;
    f(one); // Wants a Two, has a One
    //! f(Two(one)); //! 添加explicit关键字后需要用这种语法调用f()

    return 0;
} ///:~
