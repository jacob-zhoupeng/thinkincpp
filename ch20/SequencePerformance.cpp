//: C20:SequencePerformance.cpp
// Comparing the performance of the basic
// sequence containers for various operations

#include <vector>
#include <queue>
#include <list>
#include <iostream>
#include <string>
#include <typeinfo>
#include <ctime>
#include <cstdlib>

using namespace std;

class FixedSize {
public:
    // Automatic generation of default constructor,
    // copy-constructor and operator=
private:
    int x[20];
} fs;

template<class Cont>
struct InsertBack {
    void operator()(Cont& c, long count) {
        for (long i = 0; i < count; i++) {
            c.push_back(fs);
        }
    }

    char* testName() {
        return "InsertBack";
    }
};

template<class Cont>
struct InsertFront {
    void operator()(Cont& c, long count) {
        long cnt = count * 10;
        for (long i = 0; i < cnt; i++) {
            c.push_front(fs);
        }
    }

    char* testName() {
        return "InsertFront";
    }
};

template<class Cont>
struct InsertMiddle {
    void operator()(Cont& c, long count) {
        typename Cont::iterator it;

        long cnt = count / 10;
        for (long i = 0; i < cnt; i++) {
            // Must get the iterator every time to keep
            // from causing an access violation with
            // vector. Increment it to put it in the
            // middle of the container:
            it = c.begin(); //! 修改容器后需要重新获取访问迭代器
            it++;
            c.insert(it, fs);
        }
    }

    char* testName() {
        return "InsertMiddle";
    }
};

template<class Cont>
struct RandomAccess { // Not for list
    void operator()(Cont& c, long count) {
        int sz = c.size();
        long cnt = count * 100;

        for (long i = 0; i < cnt; i++) {
            c[rand() % sz];
        }
    }

    char* testName() {
        return "RandomAccess";
    }
};

template<class Cont>
struct Traversal {
    void operator()(Cont& c, long count) {
        long cnt = count / 100;

        for (long i = 0; i < cnt; i++) {
            typename Cont::iterator it = c.begin();
            typename Cont::iterator end = c.end();

            while (it != end) {
                it++;
            }
        }
    }

    char* testName() {
        return "Traversal";
    }
};

template<class Cont>
struct Swap {
    void operator()(Cont& c, long count) {
        int middle = c.size() / 2;
        typename Cont::iterator it = c.begin();
        typename Cont::iterator mid = c.begin();

        it++; // Put it in the middle

        for (int x = 0; x < middle+1; x++) {
            mid++;
        }

        long cnt = count * 10;

        for (long i = 0; i < cnt; i++) {
            swap(*it, *mid);
        }
    }

    char* testName() {
        return "Swap";
    }
};

template<class Cont>
struct RemoveMiddle {
    void operator()(Cont& c, long count) {
        long cnt = count / 10;

        if (cnt > c.size()) {
            cout << "RemoveMiddle: not enough elements"
                << endl;
            return;
        }

        for (long i = 0; i < cnt; i++) {
            typename Cont::iterator it = c.begin();
            it++;
            c.erase(it);
        }
    }

    char* testName() {
        return "RemoveMiddle";
    }
};

template<class Cont>
struct RemoveBack {
    void operator()(Cont& c, long count) {
        long cnt = count * 10;

        if (cnt > c.size()) {
            cout << "RemoveBack: not enough elements"
                << endl;
            return;
        }

        for (long i = 0; i < cnt; i++) {
            c.pop_back();
        }
    }

    char* testName() {
        return "RemoveBack";
    }
};

template<class Op, class Container>
void messureTime(Op f, Container& c, long count) {
    string id(typeid(f).name());

    bool Deque = id.find("deque") != string::npos;
    bool List = id.find("list") != string::npos;
    bool Vector = id.find("vector") != string::npos;

    string cont = Deque ? "deque" : List ? "List"
        : Vector ? "vector" : "unknown";

    cout << f.testName() << " for " << cont << ": ";

    // Standard C library CPU ticks:
    clock_t ticks = clock();
    f(c, count); // Run the test
    ticks = clock() - ticks;

    cout << ticks << endl;
}

typedef deque<FixedSize> DF;
typedef vector<FixedSize> VF;
typedef list<FixedSize> LF;

int main(int argc, char* argv[]) {
    srand(time(0));
    long count = 10000;

    if (argc >= 2) {
        count = atoi(argv[1]);
    }

    DF deq;
    LF lst;
    VF vec;
    VF vecres;

    vecres.reserve(count); // Preallocate storage

    messureTime(InsertBack<VF>(), vec, count);
    messureTime(InsertBack<VF>(), vecres, count);
    messureTime(InsertBack<DF>(), deq, count);
    messureTime(InsertBack<LF>(), lst, count);

    // Can't push_front() with a vector:
    //! messureTime(InsertFront<VF>(), vec, count);
    messureTime(InsertFront<DF>(), deq, count);
    messureTime(InsertFront<LF>(), lst, count);

    messureTime(InsertMiddle<LF>(), lst, count);
    messureTime(InsertMiddle<VF>(), vec, count);
    messureTime(InsertMiddle<DF>(), deq, count);

    messureTime(RandomAccess<VF>(), vec, count);
    messureTime(RandomAccess<DF>(), deq, count);
    // Can't operator[] with a list:
    //! messureTime(RandomAccess<LF>(), lst, count);

    messureTime(Traversal<VF>(), vec, count);
    messureTime(Traversal<DF>(), deq, count);
    messureTime(Traversal<LF>(), lst, count);

    messureTime(Swap<VF>(), vec, count);
    messureTime(Swap<DF>(), deq, count);
    messureTime(Swap<LF>(), lst, count);

    messureTime(RemoveMiddle<VF>(), vec, count);
    messureTime(RemoveMiddle<DF>(), deq, count);
    messureTime(RemoveMiddle<LF>(), lst, count);

    vec.resize(vec.size() * 10); // Make it bigger

    messureTime(RemoveBack<VF>(), vec, count);
    messureTime(RemoveBack<DF>(), deq, count);
    messureTime(RemoveBack<LF>(), lst, count);

   return 0;
} ///:~

