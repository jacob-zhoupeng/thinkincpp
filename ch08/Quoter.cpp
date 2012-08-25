//: C08:Quoter.cpp
// Random quote selection

#include <iostream>
#include <cstdlib> // Random number generator
#include <ctime> // To seed random generator

using namespace std;

class Quoter {
public:
    Quoter();
    int Lastquote() const;
    const char *quote();
private:
    int lastquote;
};

Quoter::Quoter() {
    lastquote = -1;
    srand(time(NULL)); // Seed random number generator
}

//! const函数定义和声明都要const关键字!!!
int Quoter::Lastquote() const {
    return lastquote;
}

const char *Quoter::quote() {
    //! static关键字表示多次调用函数使用同一个quotes变量
    static const char *quotes[] = {
        "Are we having fun yet?",
        "Docters always know best",
        "Is it ... Atomic?",
        "Fear is obscene",
        "There is no scientific evidence",
        "to support the idea "
        "that life is serious",
    };

    //! const qsize = sizeof(quotes) / sizeof(*quotes); // 原书代码可能有错.
    const int qsize = sizeof(quotes) / sizeof(*quotes);
    int qnum = rand() % qsize;

    while (lastquote >= 0 && qnum == lastquote) {
        qnum = rand() % qsize;
    }

    return quotes[lastquote = qnum];
}

int main() {
    Quoter q;
    const Quoter cq;

    cq.Lastquote(); // OK
    //! cq.quote(); // Not OK; non const function

    for (int i = 0; i < 20; i++) {
        cout << q.quote() << endl;
    }
} ///:~
