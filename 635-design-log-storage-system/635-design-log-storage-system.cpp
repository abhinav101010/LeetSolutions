#include <string>
#include <vector>
#include <map>
using namespace std;

class LogSystem {
private:
    vector<pair<string, int>> logs;
    map<string, int> granularity;
public:
    LogSystem() {
        granularity["Year"] = 4;
        granularity["Month"] = 7;
        granularity["Day"] = 10;
        granularity["Hour"] = 13;
        granularity["Minute"] = 16;
        granularity["Second"] = 19;
    }
    
    void put(int id, string timestamp) {
        logs.push_back({timestamp, id});
    }
    
    vector<int> retrieve(string start, string end, string granularity) {
        int g = this->granularity[granularity];
        string s = start.substr(0, g);
        string e = end.substr(0, g);
        vector<int> res;
        for (auto& p : logs) {
            string ts = p.first;
            string sub = ts.substr(0, g);
            if (s <= sub && sub <= e) {
                res.push_back(p.second);
            }
        }
        return res;
    }
};
