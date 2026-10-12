class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        unordered_set<string> points;
        long long area = 0;
        int minX = INT_MAX, minY = INT_MAX;
        int maxX = INT_MIN, maxY = INT_MIN;
        
        for (auto& r : rectangles) {
            minX = min(minX, r[0]);
            minY = min(minY, r[1]);
            maxX = max(maxX, r[2]);
            maxY = max(maxY, r[3]);
            area += (long long)(r[2] - r[0]) * (r[3] - r[1]);
            
            vector<pair<int, int>> corners = {{r[0], r[1]}, {r[0], r[3]}, {r[2], r[1]}, {r[2], r[3]}};
            for (auto& p : corners) {
                string key = to_string(p.first) + "," + to_string(p.second);
                if (points.count(key)) points.erase(key);
                else points.insert(key);
            }
        }
        
        if (points.size() != 4) return false;
        
        vector<string> expected = {
            to_string(minX) + "," + to_string(minY),
            to_string(minX) + "," + to_string(maxY),
            to_string(maxX) + "," + to_string(minY),
            to_string(maxX) + "," + to_string(maxY)
        };
        for (auto& e : expected) {
            if (!points.count(e)) return false;
        }
        
        return area == (long long)(maxX - minX) * (maxY - minY);
    }
};