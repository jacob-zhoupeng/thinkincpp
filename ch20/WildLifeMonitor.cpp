//: C20:WildLifeMonitor.cpp

#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <sstream>
#include <ctime>

using namespace std;

class DataPoint {
public:
    DataPoint() : x(0), y(0), time(0) {}
    DataPoint(int xx, int yy, time_t tm) : x(xx), y(yy), time(tm) {}

    // Synthesized operator=, copy-constructor OK
    int getX() const {
        return x;
    }

    int getY() const {
        return y;
    }

    time_t* getTime() {
        return &time;
    }
private:
    int x; // Location coordinates
    int y;
    
    time_t time; // time of Sighting
};

string animal[] = {
    "chippmunk", "beaver", "marmot", "weasel",
        "squirrel", "ptarmigan", "bear", "eagle",
        "hawk", "vole", "deer", "otter", "hummingbird",
};

const int asz = sizeof(animal) / sizeof(*animal);
vector<string> animals(animal, animal + asz);

// All the information is contained in a
// "Sighting," which can be sent to an ostream:
typedef pair<string, DataPoint> Sighting;

ostream& operator<<(ostream& os, Sighting s) {
    return os << s.first << " sighted at x = " << s.second.getX() << ", y = "
        << s.second.getY() << ", time = " << ctime(s.second.getTime());
}

// A generator for Sightings:
class SightingGen {
public:
    SightingGen(vector<string>& an) : animals(an) {
        srand(time(0));
    }

    Sighting operator()() {
        Sighting result;
        int select = rand() % animals.size();

        result.first = animals[select];
        result.second = DataPoint(rand() % d, rand() % d, time(0));

        return result;
    }
private:
    vector<string>& animals;
    static const int d = 100;
};

typedef multimap<string, DataPoint> DataMap;
typedef DataMap::iterator DMIter;

int main(int argc, char* argv[]) {
    DataMap sightings;
    generate_n(inserter(sightings, sightings.begin()), 100, SightingGen(animals));

    // Print everything:
    copy(sightings.begin(), sightings.end(), ostream_iterator<Sighting>(cout, ""));

    // Print sightings for selected animal:
    while (true) {
        cout << "select an animal or 'q' to quit: ";
        for (int i = 0; i < animals.size(); i++) {
            cout << '[' << i << ']' << animals[i] << ' ';
        }
        cout << endl;

        string reply;
        cin >> reply;
        if (reply.at(0) == 'q') {
            return 0;
        }

        istringstream r(reply);
        int i;
        r >> i; // Converts to int
        i %= animals.size();

        // Iterators in "range" denote begin, one
        // past end of matching range:
        pair<DMIter, DMIter> range = sightings.equal_range(animals[i]);

        copy(range.first, range.second, ostream_iterator<Sighting>(cout, ""));
    }

    return 0;
} ///:~
