#include <vector>
#include <string>
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
    vector<vector<string>> gameAnalysis(const vector<Activity>& activity) {
        map<int, string> firstLogin;
        for (const auto& a : activity) {
            auto it = firstLogin.find(a.player_id);
            if (it == firstLogin.end() || a.event_date < it->second)
                firstLogin[a.player_id] = a.event_date;
        }
        vector<vector<string>> result;
        for (const auto& kv : firstLogin)
            result.push_back({to_string(kv.first), kv.second});
        return result;
    }
};
