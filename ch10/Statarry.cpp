//: C10:Statarry.cpp {0}
// Initializing static arrays

class Values {
private:
    static const int size;
    static const float table[4];
    static char letters[10];
};

const int Values::size = 100;

const float Values::table[4] = {
    1.1, 2.2, 3.3, 4.4
};

char Values::letters[10] = {
    'a', 'b', 'c', 'd', 'e',
    'f', 'g', 'h', 'i', 'j'
};
///:~
