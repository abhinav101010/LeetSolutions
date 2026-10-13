class Solution {
public:
    bool isReflected(vector<vector<int>>& points) {
        if (points.empty()) return true;
        int minX = INT_MAX, maxX = INT_MIN;
        unordered_set<string> set;
        for (auto &p : points) {
            minX = min(minX, p[0]);
            maxX = max(maxX, p[0]);
            set.insert(to_string(p[0]) + "," + to_string(p[1]));
        }
        int sumX = minX + maxX;
        for (auto &p : points) {
            string key = to_string(sumX - p[0]) + "," + to_string(p[1]);
            if (set.find(key) == set.end()) return false;
        }
        return true;
    }
};