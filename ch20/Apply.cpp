//: C20:Apply.cpp
// Using basic iterators

#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

template<class Cont, class PtrMemFun>
void apply(Cont& c, PtrMemFun f) {
    typename Cont::iterator it = c.begin();
    while (it != c.end()) {
        //(it->*f)(); // Compact form //! gcc-4.4 gcc-4.6 ±àÒë²»Í¨¹ý
        ((*it).*f)(); // Alternate form
        it++;
    }
}

class Z {
public:
    Z(int ii) : i(ii) {}

    void g() {
        i++;
    }

    friend ostream& operator<<(ostream& os, const Z& z) {
        return os << z.i;
    }
private:
    int i;
};

int main() {
    ostream_iterator<Z> out(cout, " ");
    vector<Z> vz;
    for (int i = 0; i < 10; i++) {
        vz.push_back(Z(i));
    }

    copy(vz.begin(), vz.end(), out);
    cout << endl;

    apply(vz, &Z::g);
    copy(vz.begin(), vz.end(), out);

    return 0;
} ///:~

