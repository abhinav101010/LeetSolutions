#include <vector>
#include <string>
#include <set>
#include <unordered_map>
#include <algorithm>
using namespace std;

struct RequestAccepted {
    int requester_id;
    int accepter_id;
};

class Solution {
public:
    vector<vector<string>> mostFriends(vector<RequestAccepted>& requests) {
        set<pair<int, int>> s;
        for (auto& r : requests) s.insert({r.requester_id, r.accepter_id});
        unordered_map<int, int> cnt;
        for (auto& r : requests) {
            if (s.count({r.accepter_id, r.requester_id})) {
                cnt[r.requester_id]++;
            }
        }
        int bestId = -1, bestNum = -1;
        for (auto& kv : cnt) {
            if (kv.second > bestNum || (kv.second == bestNum && kv.first < bestId)) {
                bestNum = kv.second;
                bestId = kv.first;
            }
        }
        vector<vector<string>> ans;
        if (bestId >= 0) ans.push_back({to_string(bestId), to_string(bestNum)});
        return ans;
    }
};
