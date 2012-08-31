//: C16:Applist.cpp
// Apply a function to a TStack
#include <iostream>

#include "TStack.h"

using namespace std;

// 0 arguments, any type of return value:
template<class T, class R>
void applist(TStack<T> &t1, R(T::*f)()) {
    TStackIterator<T> it(t1);
    while (it) {
        (it.current()->*f)();
        it++;
    }
}

// 1 argument, any type of return value:
template<class T, class R, class A>
void applist(TStack<T> &t1, R(T::*f)(A), A a) {
    TStackIterator<T> it(t1);
    while (it) {
        (it.current()->*f)(a);
        it++;
    }
}

// 2 arguments, any type of return value:
template<class T, class R, class A1, class A2>
void applist(TStack<T> &t1, R(T::*f)(A1, A2),
    A1 a1, A2 a2) {
    TStackIterator<T> it(t1);
    while (it) {
        (it.current()->*f)(a1, a2);
        it++;
    }
}

// Etc., to handle maximum probable arguments

class Gromit { // The techo-dog
public:
    Gromit(int Arf = 1) : arf(Arf + 1) {}

    void speak(int) {
        for (int i = 0; i < arf; i++) {
            cout << "arf! ";
        }
        cout << endl;
    }

    char eat(float) {
        cout << "chomp!" << endl;
        return 'z';
    }

    int sleep(char, double) {
        cout << "zzz..." << endl;
        return 0;
    }

    void sit(void) {}
private:
    int arf;
};

int main() {
    TStack<Gromit> dogs;

    for (int i = 0; i < 5; i++) {
        dogs.push(new Gromit(i));
    }

    applist(dogs, &Gromit::speak, 1);
    applist(dogs, &Gromit::eat, 2.0f);
    applist(dogs, &Gromit::sleep, 'z', 3.0);
    applist(dogs, &Gromit::sit);

    return 0;
} ///:~
