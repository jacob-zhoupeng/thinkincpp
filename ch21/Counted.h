//: C21:Counted.h
// An object that keeps track of itself
#ifndef COUNTED_H
#define COUNTED_H

#include <vector>

class Counted {
public:
    Counted(char* ID) : id(ID) {
        count++;
    }

    ~Counted() {
        std::cout << id << " count = "
            << --count << std::endl;
    }
private:
    static int count;
    char* id;
};

int Counted::count = 0;

class CountedVector : public std::vector<Counted*> {
public:
    CountedVector(char* ID) {
        for (int i = 0; i < 5; i++) {
            push_back(new Counted(ID));
        }
    }
};

#endif // COUNTED_H ///:~