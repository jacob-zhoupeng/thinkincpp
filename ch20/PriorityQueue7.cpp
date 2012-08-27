//: C20:PriorityQueue7.cpp
// A priority queue that will hand you a vector

#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

template<class T, class Compare>
class PQV {
public:
    // Don't need to call make_heap(); it's empty:
    PQV(Compare cmp = Compare()) : comp(cmp) {}

    void push(const T& x) {
        // Put it at the end:
        v.push_back(x);

        // Re-adjust the heap:
        push_heap(v.begin(), v.end(), comp);
    }

    void pop() {
        // Move the top element to the last position:
        pop_heap(v.begin(), v.end(), comp);

        // Remove that element:
        v.pop_back();
    }

    const T& top() {
        return v.front();
    }

    bool empty() const {
        return v.empty();
    }

    typedef vector<T> TVec;
    TVec get_vector() {
        TVec r(v.begin(), v.end());

        // It's already a heap
        sort_heap(r.begin(), r.end(), comp);

        // Put it into priority-queue order:
        reverse(r.begin(), r.end());
        return r;
    }
private:
    vector<T> v;
    Compare comp;
};

int main(int argc, char* argv[]) {
    PQV<int, less<int> > pqi;
    srand(time(0));

    for (int i = 0; i < 100; i++) {
        pqi.push(rand() % 25);
    }

    //! 这里为什么必须为const???
    // 如果您知道答案，请邮件告诉我<jacob.zhoupeng@gmail.com>，非常感谢。
    const vector<int>& v = pqi.get_vector();
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
    cout << "\n----------\n";

    while (!pqi.empty()) {
        cout << pqi.top() << ' ';
        pqi.pop();
    }

    return 0;
} ///:~


