//: C03:FileStatic.cpp
// File scope demonstration. Compiling and linking
// this file with FileStatic2.cpp will cause a linker
// error.

static int fs; // File scope: only available in this file

int main() {
    fs = 1;

    return 0;
} ///:~
