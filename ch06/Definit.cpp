//: C06:Definit.cpp
// defining variables anywhere

#include <cstdio>
#include <cstdlib>

#include "../require.h"

using namespace std;

class G {
public:
    G(int I);
private:
    int i;
};

G::G(int I) {
    i = I;
}

int main() {
#define SZ (100)
    char buf[SZ];
    printf("initialization value? ");
    int retval = (int) gets(buf);
    require(retval != 0);
    int x = atoi(buf);
    int y = x + 3;
    G g(y);

    return 0;
} ///:~
