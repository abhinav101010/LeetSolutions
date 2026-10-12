#include <string>
#include <unordered_map>
using namespace std;

class UndergroundSystem {
    struct CheckIn {
        string station;
        int time;
        CheckIn(string s, int t) : station(move(s)), time(t) {}
    };
    struct Route {
        int totalTime = 0;
        int count = 0;
        Route(int t = 0, int c = 0) : totalTime(t), count(c) {}
    };

    unordered_map<int, CheckIn> checkIns;
    unordered_map<string, Route> routes;

public:
    UndergroundSystem() {}

    void checkIn(int id, string stationName, int time) {
        checkIns.emplace(id, CheckIn(move(stationName), time));
    }

    void checkOut(int id, string stationName, int time) {
        auto it = checkIns.find(id);
        CheckIn entry = move(it->second);
        checkIns.erase(it);

        string routeName = entry.station + "->" + stationName;
        int duration = time - entry.time;

        auto& route = routes[routeName];
        route.totalTime += duration;
        route.count++;
    }

    double getAverageTime(string startStation, string endStation) {
        string routeName = startStation + "->" + endStation;
        Route& route = routes[routeName];
        return static_cast<double>(route.totalTime) / route.count;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id, stationName, time);
 * obj->checkOut(id, stationName, time);
 * double param_3 = obj->getAverageTime(startStation, endStation);
 */