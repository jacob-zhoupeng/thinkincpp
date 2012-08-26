//: C20:PriorityQueue6.cpp

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
        sorted = false;
    }

    const T& top() {
        assureHeap();
        return front();
    }

    void push(const T& x) {
        assureHeap();
        
        // Put it at the end:
        push_back(x);

        // Re-adjust the heap:
        push_heap(begin(), end(), comp);
    }

    void pop() {
        assureHeap();

        // Move the top element to the last position:
        pop_heap(begin(), end(), comp);

        // Remove that element:
        pop_back();
    }

    void sort() {
        if (!sorted) {
            sort_heap(begin(), end(), comp);
            reverse(begin(), end());
            sorted = true;
        }
    }
private:
    Compare comp;
    bool sorted;
    void assureHeap() {
        if (sorted) {
            // Turn it back into a heap:
            make_heap(begin(), end(), comp);
            sorted = false;
        }
    }
};

int main() {
    PQV<int, less<int> > pqi;
    srand(time(0));

    for (int i = 0; i < 100; i++) {
        pqi.push(rand() % 25);
        copy(pqi.begin(), pqi.end(), ostream_iterator(cout, " "));
        cout << "\n-----\n";
    }

    pqi.sort();

    copy(pqi.begin(), pqi.end(), ostream_iterator<int>(cout, " "));
    cout << "\n-----\n";

    while (!pqi.empty()) {
        cout << pqi.top() << ' ';
        pqi.pop();
    }

    return 0;
} ///:~

