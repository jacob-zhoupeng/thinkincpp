//: C12:FeeFi2.cpp
// Copying vs. initialization

class Fi {
    // Empty class
};

class Fee {
public:
    Fee(int){
        // Empty body
    }
    Fee(const Fee &){
        // Empty body
    }
};

class Fo {
public:
    Fo(int x = 0) {
        i = x;
    }
    operator Fee() const  {
        return Fee(i);
    }
private:
    int i;
};

int main() {
    Fo fo;
    Fee fiddle = fo; //! �ȵ���Fo������غ�����foת����
                     //! Fee����Ȼ�����Fee��ĸ��ƹ��캯��

    return 0;
} ///:~
