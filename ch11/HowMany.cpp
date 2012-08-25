//: C11:HowMany.cpp
// Class counts its objects

#include <fstream>

using namespace std;

ofstream out("HowMany.out");

class HowMany {
public:
    HowMany() {
        object_count++;
    }
    static void print(const char *msg = NULL) {
        if (msg != NULL) {
            out << msg << ": ";
        }
        out << "object_count = "
            << object_count << endl;
    }
    ~HowMany() {
        object_count--;
        print("~HowMany()");
    }
private:
    static int object_count; //! 静态成员声明时不分配存储空间
};

//! 此时静态成员才分配存储空间
int HowMany::object_count = 0;

// Pass and return BY VALUE
HowMany f(HowMany x) {
    x.print("x argument inside f()");

    return x;
}

int main() {
    HowMany h;

    HowMany::print("after construction of h");

    HowMany h2 = f(h);

    HowMany::print("after call to f()");

    return 0;
} ///:~
