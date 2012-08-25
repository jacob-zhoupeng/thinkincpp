//: C08:Volatile.cpp
// The volatile keyword

class Comm {
public:
    Comm();
    void isr() volatile;
    char read(int Index) const;
private:
    const volatile unsigned char byte;
    volatile unsigned char flag;
    //! 枚举可作为类常量使用
    enum {
        bufsize = 100
    };
    unsigned char buf[bufsize];
    int index;
};

Comm::Comm() : index(0), byte(0), flag(0) {
    // do nothing here
}

// Only a demo; won't actually work
// as an interrupt service routine:
void Comm::isr() volatile {
    if (flag) {
        flag = 0;
    }
    buf[index++] = byte;
    // Wrap to beginning of buffer:
    if (index >= bufsize) {
        index = 0;
    }
}

char Comm::read(int Index) const {
    if (Index < 0 || Index >= bufsize) {
        return 0;
    }
    return buf[Index];
}

int main() {
    volatile Comm Port;

    Port.isr(); // OK
    //! Port.read(0); // Not OK; read() not volatile

    return 0;
} ///:~
