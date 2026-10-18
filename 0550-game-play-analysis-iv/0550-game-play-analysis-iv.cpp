#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <tuple>
#include <utility>

using namespace std;

struct Activity {
    int machine_id;
    int process_id;
    string activity_type; // "start" or "end"
    int timestamp;
};

class Solution {
public:
    vector<pair<int, double> > processingTime(vector<Activity> &activity) {
        // join start and end events by machine_id and process_id
        unordered_map<long long, int> start_ts;
        // key = machine_id * 2000000000LL + process_id? or just combine; process_id can vary
        unordered_map<string, int> start_ts_map;
        for (const auto &a : activity) {
            if (a.activity_type == "start") {
                string key = to_string(a.machine_id) + ":" + to_string(a.process_id);
                // keep first if duplicate? not stated
                start_ts_map[key] = a.timestamp;
            }
        }
        // collect end times and compute durations per (machine_id, process_id)
        struct Duration {
            int machine_id;
            int duration;
        };
        vector<Duration> durations;
        for (const auto &a : activity) {
            if (a.activity_type == "end") {
                string key = to_string(a.machine_id) + ":" + to_string(a.process_id);
                auto it = start_ts_map.find(key);
                if (it != start_ts_map.end()) {
                    durations.push_back({a.machine_id, a.timestamp - it->second});
                }
            }
        }
        // group by machine_id and avg
        unordered_map<int, vector<int> > by_machine;
        for (const auto &d : durations) {
            by_machine[d.machine_id].push_back(d.duration);
        }
        vector<pair<int, double> > res;
        for (const auto &p : by_machine) {
            double sum = 0;
            const auto &v = p.second;
            for (int x : v) sum += x;
            double avg = v.empty() ? 0.0 : sum / v.size();
            // round to 3 decimals
            avg = round(avg * 1000.0) / 1000.0;
            res.push_back({p.first, avg});
        }
        // sort by machine_id for consistency
        sort(res.begin(), res.end());
        return res;
    }
};
