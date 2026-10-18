#include <vector>
#include <string>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <set>
#include <cstdint>

using namespace std;

struct Activity {
    int user_id;
    int session_id;
    string activity_date;
    string activity_type;
};

class Solution {
public:
    vector<pair<string, int> > userActivity(vector<Activity> &activity) {
        map<string, set<int> > day_users;
        for (const auto &a : activity) {
            if (a.activity_date >= "2019-06-28" && a.activity_date <= "2019-07-27") {
                day_users[a.activity_date].insert(a.user_id);
            }
        }
        vector<pair<string, int> > res;
        for (const auto &p : day_users) {
            res.push_back({p.first, (int)p.second.size()});
        }
        return res;
    }
};
