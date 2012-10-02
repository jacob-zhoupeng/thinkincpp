//: C26:FormDump.cpp
// {L} FormData
#include "FormData.h"
#include "../require.h"

int main(int argc, char* argv[]) {
    requireArgs(argc, 2);

    FormData fd(argv[1]);
    fd.dump();

    return 0;
} ///:~