#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

struct Follower {
    int user_id;
    int follower_id;
};

class Solution {
public:
    vector<vector<string>> findFollowersCount(vector<Follower>& followers) {
        unordered_map<int, int> cnt;
        for (auto& f : followers) cnt[f.user_id]++;
        vector<vector<string>> ans;
        for (auto& kv : cnt) ans.push_back({to_string(kv.first), to_string(kv.second)});
        sort(ans.begin(), ans.end(), [](const vector<string>& a, const vector<string>& b) {
            return stoi(a[0]) < stoi(b[0]);
        });
        return ans;
    }
};
