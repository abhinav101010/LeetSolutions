#include <vector>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

struct Activity {
    int player_id;
    int device_id;
    string event_date;
    int games_played;
};

class Solution {
public:
    vector<vector<string>> gamePlayAnalysisII(vector<Activity>& activity) {
        vector<vector<string>> res;
        // group by player_id, find min event_date
        map<int, Activity> first;
        for (const auto& a : activity) {
            if (first.find(a.player_id) == first.end() || 
                a.event_date < first[a.player_id].event_date) {
                first[a.player_id] = a;
            }
        }
        for (auto& [pid, act] : first) {
            res.push_back({to_string(pid), to_string(act.device_id)});
        }
        sort(res.begin(), res.end(), [](auto& a, auto& b) {
            return stoi(a[0]) < stoi(b[0]);
        });
        return res;
    }
};
