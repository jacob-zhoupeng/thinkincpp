//: C22:MultipleInheritance1.cpp
// MI & ambiguity
#include <iostream>
#include <vector>

#include "../purge.h"

using namespace std;

class Base {
public:
	virtual char* vf() const = 0;
	virtual ~Base() {}
};

class D1 : public Base {
public:
	char* vf() const {
		return "D1";
	}
};

class D2 : public Base {
public:
	char* vf() const {
		return "D2";
	}
};

// Causes error: ambiguous override of vf():
//! class MI : public D1, public D2 {};

int main(int argc, char* argv[]) {
	vector<Base*> b;

	b.push_back(new D1);
	b.push_back(new D2);

	// Cannot upcast: which subobject?:
	//! b.push_back(new mi);
	for (int i = 0; i < b.size(); i++) {
		cout << b[i]->vf() << endl;
	}
	purge(b);

	return 0;
} ///:~
