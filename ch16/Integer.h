//: C16:Integer.h
// An int wrapped in a class
#ifndef INTEGER_H_INCLUDED
#define INTEGER_H_INCLUDED

class Integer {
public:
    // Guranteed zeroing:
    Integer(int ii = 0) : i(ii) {
        // Empty body
    }

    operator int() const {
        return i;
    }

    //! pre-increment
    const Integer &operator++() {
        i++;
        return *this;
    }

    //! post-increment
    const Integer operator++(int) {
        Integer returnval(i);
        i++;
        return returnval;
    }

    Integer &operator+=(const Integer &x) {
        i += x.i;
        return *this;
    }

    friend std::ostream &operator<<(std::ostream &os, const Integer &x) {
        return os << x.i;
    }
private:
    int i;
};

#endif // INTEGER_H_INCLUDED
