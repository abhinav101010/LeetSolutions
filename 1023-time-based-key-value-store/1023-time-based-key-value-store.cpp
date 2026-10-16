#include <string>
#include <unordered_map>
#include <map>
using namespace std;
class TimeMap {
    unordered_map<string, map<int,string> > store;
public:
    TimeMap() {}
    void set(string key, string value, int timestamp) {
        store[key][timestamp] = value;
    }
    string get(string key, int timestamp) {
        if (store.find(key) == store.end()) return "";
        auto &mp = store[key];
        auto it = mp.upper_bound(timestamp);
        if (it == mp.begin()) return "";
        --it;
        return it->second;
    }
};
