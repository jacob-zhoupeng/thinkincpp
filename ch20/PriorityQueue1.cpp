//: C20:PriorityQueue1.cpp

#include <iostream>
#include <queue>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(int argc, char* argv[]) {
    priority_queue<int> pqi;

    // Seed random number generator
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