//: C20:PriorityQueue2.cpp
// Changing the priority

#include <iostream>
#include <queue>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Reverse {
    bool operator()(int x, int y) {
        return y < x;
    }
};

int main() {
    priority_queue<int, vector<int>, Reverse> pqi;

    // Could alse say:
    // priority_queue<int, vector<int>, greater<int> > pqi;

    srand(time(0));

    for (int i = 0; i < 100; i++) {
        pqi.push(rand() % 25);
    }

    while (!pqi.empty()) {
        cout << pqi.top() << ' ';
        pqi.pop();
    }
    
    return 0;
} ///:~

