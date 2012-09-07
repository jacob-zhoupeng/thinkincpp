//: C21:Inventory.h
#ifndef INVENTORY_H
#define INVENTORY_H

#include <iostream>
#include <cstdlib>
#include <ctime>

class Inventory {
public:
    Inventory(char it, int quant, int val) 
        : item(it), quantity(quant), value(val) {}

    // Synthesized operator= & copy-constructor OK
    char getItem() const {
        return item;
    }

    int getQuantity() const {
        return quantity;
    }

    int getValue() const {
        return value;
    }

    void setValue(int val) {
        value = val;
    }

    friend std::ostream& operator<<(std::ostream& os, 
            const Inventory& inv) {
        return os << inv.item << ": " 
            << "quantity " << inv.quantity
            << ", value " << inv.value;  
    }
private:
    char item;
    int quantity;
    int value;
};

// A generator:
struct InvenGen {
    InvenGen() {
        std::srand(std::time(0));
    }

    Inventory operator()() {
        static char c = 'a';
        int q = std::rand() % 100;
        int v = std::rand() % 500;
        return Inventory(c++, q, v);
    }
};

#endif // INVENTORY_H ///:~