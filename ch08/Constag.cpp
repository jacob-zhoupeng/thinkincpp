//: C08:Constag.cpp {0}
// Constants and aggregates

const int i[] = { 1, 2, 3, 4 };
//! float f[i[3]]; // Illegal

struct s {
    int i;
    int j;
};

const s S[] = {
    { 1, 2 },
    { 3, 4 }
};

//! double d[S[1].j]; // Illegal
///:~
