//: C21:CalcInventory.cpp
// More use of for_each()
#include <vector>
#include <algorithm>

#include "Inventory.h"
#include "PrintSequence.h"

using namespace std;

// To calculate inventory totals:
class InvAccum {
public:
    InvAccum() : quantity(0), value(0) {}

    void operator()(const Inventory& inv) {
        quantity += inv.getQuantity();
        value += inv.getQuantity() * inv.getValue();
    }

    friend ostream& operator<<(ostream& os, const InvAccum& ia) {
        return os << "total quantity: " << ia.quantity 
            << ", total value: " << ia.value;
    }
private:
    int quantity;
    int value;
};

int main(int argc, char* argv[]) {
    vector<Inventory> vi;
    
    generate_n(back_inserter(vi), 15, InvenGen());
    print<Inventory>(vi, "vi");

    InvAccum ia = for_each(vi.begin(), vi.end(), InvAccum());
    cout << ia << endl;

    return 0;
} ///:~