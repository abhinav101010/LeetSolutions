#include <vector>
#include <map>
#include <queue>
using namespace std;
class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        map<int, priority_queue<int>> scores;
        for (auto& it : items) scores[it[0]].push(it[1]);
        vector<vector<int>> res;
        for (auto& [sid, pq] : scores) {
            int sum = 0;
            for (int k = 0; k < 5; k++) sum += pq.top(), pq.pop();
            res.push_back({sid, sum/5});
        }
        return res;
    }
};
