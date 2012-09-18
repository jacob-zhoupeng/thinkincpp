//: C24:Selfrtti.cpp
// Your own RTTI system
#include <iostream>
#include <vector>

#include "../purge.h"

using namespace std;

class Security {
public:
    virtual int dynamic_type(int ID) {
        if (ID == baseID) {
            return 1;
        }
        return 0;
    }
protected:
    enum {
        baseID = 1000
    };
};

class Stock : public Security {
public:
    int dynamic_type(int ID) {
        if (ID == typeID) {
            return 1;
        }
        return Security::dynamic_type(ID);
    }

    static Stock* dynacast(Security* s) {
        if (s->dynamic_type(typeID)) {
            return (Stock*)s;
        }
        return 0;
    }
protected:
    enum {
        typeID = baseID + 1
    };
};

class Bond : public Security {
public:
    int dynamic_type(int ID) {
        if (ID == typeID) {
            return 1;
        }
        return Security::dynamic_type(ID);
    }

    static Bond* dynacast(Security* s) {
        if (s->dynamic_type(typeID)) {
            return (Bond*)s;
        }
        return 0;
    }
protected:
    enum {
        typeID = baseID + 2
    };
};

class Commodity : public Security {
public:
    int dynamic_type(int ID) {
        if (ID == typeID) {
            return 1;
        }
        return Security::dynamic_type(ID);
    }

    static Commodity* dynacast(Security* s) {
        if (s->dynamic_type(typeID)) {
            return (Commodity*)s;
        }
        return 0;
    }

    void special() {
        cout << "special Commodity function\n";
    }
protected:
    enum {
        typeID = baseID + 3
    };
};

class Metal : public Commodity {
public:
    int dynamic_type(int ID) {
        if (ID == typeID) {
            return 1;
        }
        return Commodity::dynamic_type(ID);
    }

    static Metal* dynacast(Security* s) {
        if (s->dynamic_type(typeID)) {
            return (Metal*)s;
        }
        return 0;
    }
protected:
    enum {
        typeID = baseID + 4
    };
};

int main(int argc, char* argv[]) {
    vector<Security*> portfolio;

    portfolio.push_back(new Metal);
    portfolio.push_back(new Commodity);
    portfolio.push_back(new Bond);
    portfolio.push_back(new Stock);

    vector<Security*>::iterator it = portfolio.begin();
    while (it != portfolio.end()) {
        Commodity* cm = Commodity::dynacast(*it);

        if (cm) {
            cm->special();
        } else {
            cout << "not a Commodity" << endl;
        }

        it++;
    }

    cout << "cast from intermediate pointer:\n";
    Security* sp = new Metal;
    Commodity* cp = Commodity::dynacast(sp);

    if (cp) {
        cout << "it's a Commodity\n";
    }

    Metal* mp = Metal::dynacast(sp);
    if (mp) {
        cout << "it's a Metal too!\n";
    }

    delete sp;
    purge(portfolio);

    return 0;
} ///:~
