//: C21:TransformNames.cpp
// More use of transform()
#include <vector>
#include <algorithm>

#include "Inventory.h"
#include "PrintSequence.h"

using namespace std;

struct NewImproved {
    Inventory operator()(const Inventory& inv) {
        return Inventory(toupper(inv.getItem()), 
            inv.getQuantity(), inv.getValue());
    }
};

int main(int argc, char* argv[]) {
    vector<Inventory> vi;
    
    generate_n(back_inserter(vi), 15, InvenGen());
    print<Inventory>(vi, "vi");

    transform(vi.begin(), vi.end(), vi.begin(), NewImproved());
    print<Inventory>(vi, "vi");

    return 0;
} ///:~