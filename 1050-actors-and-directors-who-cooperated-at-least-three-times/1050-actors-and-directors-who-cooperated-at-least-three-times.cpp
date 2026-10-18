#include <vector>
#include <map>
using namespace std;

struct ActorDirector {
    int actor_id;
    int director_id;
    int timestamp;
};

class Solution {
public:
    vector<vector<int>> actorsAndDirectors(vector<ActorDirector>& actorDirector) {
        map<pair<int, int>, int> cnt;
        for (const ActorDirector& a : actorDirector) {
            cnt[{a.actor_id, a.director_id}]++;
        }
        vector<vector<int>> ans;
        for (const auto& kv : cnt) {
            if (kv.second >= 3) {
                ans.push_back({kv.first.first, kv.first.second});
            }
        }
        return ans;
    }
};
