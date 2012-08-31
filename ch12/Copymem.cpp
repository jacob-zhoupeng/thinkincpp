//: C12:Copymem.cpp {0}
// Duplicate during assignment

#include <cstdlib>
#include <cstring>

#include "../require.h"

using namespace std;

class WithPointer {
public:
    //! ���캯��
    WithPointer() {
        p = (char *) malloc(blocksz);
        require(p != NULL);
        memset(p, 1, blocksz);
    }
    //! ���ƹ��캯��
    WithPointer(const WithPointer &wp) {
        p = (char *) malloc(blocksz);
        require(p != NULL);
        memcpy(p, wp.p, blocksz);
    }
    //! ���ظ�ֵ�����
    WithPointer &operator=(const WithPointer &wp) {
        // Check for self-assignment:
        if (&wp != this) {
            memcpy(p, wp.p, blocksz);
        }
        return *this;
    }
    //! ��������
    ~WithPointer() {
        free(p);
    }
private:
    char *p;
    enum {
        blocksz = 100
    };
};
