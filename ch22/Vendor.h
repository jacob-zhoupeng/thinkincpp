//: C22:Vendor.h
// Vendor-supplied class header
// You only get this & the compiled VENDOR.OBJ
#ifndef VENDOR_H_
#define VENDOR_H_

class Vendor {
public:
    virtual void v() const;
    void f() const;
    ~Vendor();
};

class Vendor1 : public Vendor {
public:
    void v() const;
    void f() const;
    ~Vendor1();
};

void A(const Vendor&);
void B(const Vendor&);

// Etc.

#endif // VENDOR_H_ ///:~