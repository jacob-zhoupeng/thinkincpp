//: C09:Access.cpp
// Inline access functions

class Access {
public:
    //! һ�㽲���ʺʹ�ȡ��������Ϊinline���������벻�˳�
    //! ��10�� ������չ�����³���������󣬲���ά�����
    //! �μ�<<Effective C++>>������������������
    int read() const {
        return i;
    }
    void set(int I) {
        i = I;
    }
private:
    int i;
};

int main() {
    Access A;

    A.set(100);
    int x = A.read();

    return 0;
} ///:~

