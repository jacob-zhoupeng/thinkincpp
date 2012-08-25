//: C09:Access.cpp
// Inline access functions

class Access {
public:
    //! 一般讲访问和存取函数定义为inline函数，代码不宜超
    //! 过10行 ，否者展开导致程序体积过大，不易维护理解
    //! 参见<<Effective C++>>关于内联函数的条款
    int read() const {
        return i;
    }
    void set(int I) {
        i = I;
    }
private:
    int i;
};

int main() {
    Access A;

    A.set(100);
    int x = A.read();

    return 0;
} ///:~

