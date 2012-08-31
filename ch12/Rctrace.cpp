//: C12:Rctrace.cpp
// REFCOUNT.CPP w/ trace info

#include <cstring>
#include <fstream>

#include "../require.h"

using namespace std;

ofstream out("rctrace.out");

class Counted {
public:
    //! 构造函数
    Counted(const char *ID = "tmp") {
        block = new MemBlock; // Sneak preview
        strncpy(id, ID, sz);
    }
    //! 复制构造函数
    Counted(const Counted &rv) {
        block = rv.block; // Pointer assignment
        block->attach();
        strncpy(id, rv.id, sz);
        strncat(id, " copy", sz - strlen(id));
    }
    //! 重载'='运算符
    Counted &operator=(const Counted &rv) {
        print("inside operator=\n\t");
        if (&rv == this) {
            out << "self-assignment" << endl;
            return *this;
        }
        // Clean up what you're using first:
        block->detach();
        block = rv.block; // Like copy-constructor
        block->attach();
        return *this;
    }
    //! 析构函数
    // Decrement refcount, conditionally destroy
    ~Counted() {
        out << "preparing to destroy: " << id
        << endl << "\tdecrementing refcount ";
        block->print();
        out << endl;
        block->detach();
    }
    void unalias() {
        block = block->unalias();
    }
    void addname(const char *nm) {
        strncat(id, nm, sz - strlen(id));
    }
    // Copy-on-write:
    void write(char value) {
        unalias();
        block->set(value);
    }
    void print(const char *msg = "") {
        if (*msg != '\0') {
            out << msg << " ";
        }
        out << "object " << id << ":";
        block->print();
        out << endl;
    }
private:
    class MemBlock {
    public:
        MemBlock() {
            memset(c, 1, size);
            refcount = 1;
            blocknum = blockcount++;
        }
        MemBlock(const MemBlock &rv) {
            memcpy(c, rv.c, size);
            refcount = 1;
            blocknum = blockcount++;
            print("copied block");
            out << endl;
            rv.print("from block");
        }
        ~MemBlock() {
            out << "\tdestroying block " << blocknum << endl;
        }
        void print(const char *msg = "") const {
            if (*msg != '\0') {
                out << msg << ", ";
            }
            out << "blocknum: " << blocknum;
            out << ", refcount: " << refcount;
        }
        void attach() {
            ++refcount;
        }
        void detach() {
            require(refcount != 0);
            // Destroy object if no one is using it:
            if (--refcount == 0) {
                delete this;
            }
        }
        int count() const {
            return refcount;
        }
        void set(char x) {
            memset(c, x, size);
        }
        // Conditionally copy this MemBlock.
        // Call before modifying the block; assign
        // resulting pointer to your block;
        MemBlock *unalias() {
            // Don't duplicate if not aliased:
            if (refcount == 1) {
                return this;
            }
            --refcount;
            // Use copy-constructor to duplicate:
            return new MemBlock(*this);
        }
    private:
        enum {
            size = 100
        };
        char c[size];
        int refcount;
        int blocknum;
        static int blockcount;
    } *block;
    enum {
        sz = 30
    };
    char id[sz];
};

int Counted::MemBlock::blockcount = 0;

int main() {
    Counted A("A"), B("B");
    Counted C(A);

    C.addname(" (C) ");
    A.print();
    B.print();
    C.print();
    B = A;

    A.print("after assignment\n\t");
    B.print();

    out << "Assigning C = C" << endl;
    C = C;

    C.print("calling C write('x')\n\t");
    C.write('x');
    out << endl << "exiting main()" << endl;

    return 0;
} ///:~
