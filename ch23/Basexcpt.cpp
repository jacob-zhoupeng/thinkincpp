//: C23:Basexcpt.cpp
// Exception hierarchies
#include <iostream>

using namespace std;

class X {
public:
    class Trouble {};
    class Small : public Trouble {};
    class Big : public Trouble {};

    void f() {
        throw Big();
    }
};

int main(int argc, char* argv[]) {
    X x;
    
    try {
        x.f();
    } catch (X::Trouble) {
        cout << "caught Trouble" << endl;
    //! Hidden by previous handler:
    } catch (X::Small) {
        cout << "caught Small Trouble" << endl;
    } catch (X::Big) {
        cout << "caught Big Trouble" << endl;
    }

    return 0;
} ///:~