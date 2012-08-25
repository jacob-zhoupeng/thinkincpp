//: C13:GlobalNew.cpp
// Overload global new/delete

#include <cstdio>
#include <cstdlib>

using namespace std;

void *operator new(size_t sz) {
    printf("operator new: %d Bytes\n", sz);
    void *m = malloc(sz);
    if (m == NULL) {
        puts("out of memory");
    }
    return m;
}

void  operator delete(void *m) {
    puts("operator delete"); //! puts()����Ĭ�ϻ���ӻ��з�
    free(m);
}

class S {
public:
    S() {
        puts("S::S()");
    }
    ~S() {
        puts("S::~S()");
    }
private:
    int i[100];
};

int main() {
    puts("creating & destroying an int");
    int *p = new int(47);
    delete p;

    puts("creating & destroying an s");
    S *s = new S;
    delete s;

    puts("creating & destroying S[3]");
    S *sa = new S[3]; //! ���������ռ�洢S�������!!!
    delete[] sa;

    return 0;
} ///:~
