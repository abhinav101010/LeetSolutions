class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> events;
        for (auto& b : buildings) {
            events.push_back({b[0], -b[2], b[1]});  // Start
            events.push_back({b[1], b[2], 0});      // End
        }
        
        sort(events.begin(), events.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] != b[0]) return a[0] < b[0];
            return a[1] < b[1];
        });
        
        vector<vector<int>> result;
        // min-heap: (height, end)
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, INT_MAX});
        
        for (auto& e : events) {
            int x = e[0], h = e[1], r = e[2];
            if (h < 0) {
                pq.push({h, r});
            } else {
                while (!pq.empty() && pq.top().second <= x) {
                    pq.pop();
                }
            }
            
            int maxH = -pq.top().first;
            if (result.empty() || result.back()[1] != maxH) {
                result.push_back({x, maxH});
            }
        }
        
        return result;
    }
};