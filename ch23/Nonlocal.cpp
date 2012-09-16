//: C23:Nonlocal.cpp
// setjmp() & longjmp()
#include <iostream>
#include <csetjmp>

using namespace std;

class Rainbow {
public:
    Rainbow() {
        cout << "Rainbow()" << endl;
    }

    ~Rainbow() {
        cout << "~Rainbow()" << endl;
    }
};

jmp_buf kansas;

void oz() {
    Rainbow rb;

    for (int i = 0; i < 3; i++) {
        cout << "there's no place like home\n";
    }

    longjmp(kansas, 47);
}

int main(int argc, char* argv[]) {
    if (0 == setjmp(kansas)) {
        cout << "tornado, witch, munchkins...\n";
        oz();
    } else {
        cout << "Auntie Em! " << "I had the strangest dream..."
            << endl;
    }

    return 0;
} ///:~