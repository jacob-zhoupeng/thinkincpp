//: C21:SpecialList.cpp
// Using the second version of transform()
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

#include "Inventory.h"
#include "PrintSequence.h"

using namespace std;

struct Discounter {
    Inventory operator()(const Inventory& inv, float discount) {
        return Inventory(inv.getItem(), inv.getQuantity(), 
            inv.getValue() * (1 - discount));
    }
};

struct DiscGen {
    DiscGen() {
        srand(time(0));
    }

    float operator()() {
        float r = float(rand() % 10);
        return r / 100.;
    }
};

int main(int argc, char* argv[]) {
    vector<Inventory> vi;
    
    generate_n(back_inserter(vi), 15, InvenGen());
    print<Inventory>(vi, "vi");

    vector<float> disc;
    generate_n(back_inserter(disc), 15, DiscGen());
    print<float>(disc, "Discounts:");

    vector<Inventory> discounted;
    transform(vi.begin(), vi.end(), disc.begin(), 
        back_inserter(discounted), Discounter());
    print<Inventory>(discounted, "discounted");

    return 0;
} ///:~