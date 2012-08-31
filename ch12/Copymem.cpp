//: C12:Copymem.cpp {0}
// Duplicate during assignment

#include <cstdlib>
#include <cstring>

#include "../require.h"

using namespace std;

class WithPointer {
public:
    //! 构造函数
    WithPointer() {
        p = (char *) malloc(blocksz);
        require(p != NULL);
        memset(p, 1, blocksz);
    }
    //! 复制构造函数
    WithPointer(const WithPointer &wp) {
        p = (char *) malloc(blocksz);
        require(p != NULL);
        memcpy(p, wp.p, blocksz);
    }
    //! 重载赋值运算符
    WithPointer &operator=(const WithPointer &wp) {
        // Check for self-assignment:
        if (&wp != this) {
            memcpy(p, wp.p, blocksz);
        }
        return *this;
    }
    //! 析构函数
    ~WithPointer() {
        free(p);
    }
private:
    char *p;
    enum {
        blocksz = 100
    };
};
