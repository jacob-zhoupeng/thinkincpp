//: C12:Autocnst.cpp
// Type conversion constructor

class One {
public:
    One() {
        // Empty body
    }
};

class Two {
public:
    //! ���explicit�ؼ��ֿ���ǿ�Ʊ�����Ҫ����ʾת������
    /* explicit */ Two(const One &) {
        // Empty body
    }
};

void f(Two) {
    // Empty body
}

int main() {
    One one;
    f(one); // Wants a Two, has a One
    //! f(Two(one)); //! ���explicit�ؼ��ֺ���Ҫ�������﷨����f()

    return 0;
} ///:~
