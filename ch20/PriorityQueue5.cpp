//: C20:PriorityQueue5.cpp
// Building your own priority queue

#include <iostream>
#include <iterator>
#include <queue>
#include <cstdlib>
#include <ctime>

using namespace std;

template<class T, class Compare>
class PQV : public vector<T> {
public:
    PQV(Compare cmp = Compare()) : comp(cmp) {
        make_heap(begin(), end(), comp);
    }

    const T& top() {
        return front();
    }

    void push(const T& x) {
        push_back(x);
        push_heap(begin(), end(), comp);
    }

    void pop() {
        pop_heap(begin(), end(), comp);
        pop_back();
    }
private:
    Compare comp;
};

int main(int argc, char* arg[]) {
    PQV<int, less<int> > pqi;
    srand(time(0));

    for (int i = 0; i < 100; i++) {
        pqi.push(rand() % 25);
    }

    copy(pqi.begin(), pqi.end(), ostream_iterator<int>(cout, " "));

    cout << endl;

    while (!pqi.empty()) {
        cout << pqi.top() << ' ';
        pqi.pop();
    }
    
    return 0;
} ///:~

