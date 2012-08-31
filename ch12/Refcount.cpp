//: C12:Refcount.cpp
// Reference count, copy-on-write(副本上写)

#include <cstring>

#include "../require.h"

using namespace std;

class Counted {
public:
    //! 构造函数
    Counted() {
        block = new MemBlock; // Sneak preview
    }
    //! 复制构造函数
    Counted(const Counted &rv) {
        block = rv.block; // Pointer assignment
        block->attach();
    }
    //! 重载'='运算符
    Counted &operator=(const Counted &rv) {
        // Check for self-assignment:
        if (&rv == this) {
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
        block->detach();
    }
    void unalias() {
        block = block->unalias();
    }
    // Copy-on-write:
    void write(char value) {
        // Do this before any write operation:
        unalias();
        // It's safe to write now.
        block->set(value);
    }

private:
    //! 私有内部类MemBlock
    class MemBlock {
    public:
        MemBlock() {
            memset(c, 1, size);
            refcount = 1;
        }
        MemBlock(const MemBlock &rv) {
            memcpy(c, rv.c, size);
            refcount = 1;
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
    } *block;
};

int main() {
    Counted A;
    Counted B;
    Counted C(A);

    B = A;
    C = C;
    C.write('x');

    return 0;
} ///:~
