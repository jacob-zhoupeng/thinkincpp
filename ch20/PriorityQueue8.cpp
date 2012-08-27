//: C20:PriorityQueue8.cpp
// A more compact version of PriorityQueue7.cpp

#include <iostream>
#include <iterator>
#include <queue>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

template<class T>
class PQV : public priority_queue<T> {
public:
    typedef vector<T> TVec;
    TVec get_vector() {
        TVec r(this->c.begin(), this->c.end());

        // c is already a heap
        sort_heap(r.begin(), r.end(), this->comp);

        // Put it into priority-queue order:
        reverse(r.begin(), r.end());
        return r;
    }
};

int main(int argc, char* argv[]) {
    PQV<int> pqi;
    srand(time(0));

    for (int i = 0; i < 100; i++) {
        pqi.push(rand() % 25);
    }

    //! ����Ϊʲô����Ϊconst???
    // �����֪���𰸣����ʼ�������<jacob.zhoupeng@gmail.com>���ǳ���л��
    const vector<int>& v = pqi.get_vector();
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
    cout << "\n----------\n";

    while (!pqi.empty()) {
        cout << pqi.top() << ' ';
        pqi.pop();
    }

    return 0;
} ///:~
