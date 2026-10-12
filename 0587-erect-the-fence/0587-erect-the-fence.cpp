class Solution {
private:
    int cross(const vector<int>& o, const vector<int>& a, const vector<int>& b) {
        return (a[0] - o[0]) * (b[1] - o[1]) - (a[1] - o[1]) * (b[0] - o[0]);
    }

public:
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        if (trees.size() <= 1) return trees;
        
        sort(trees.begin(), trees.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] != b[0] ? a[0] < b[0] : a[1] < b[1];
        });
        
        vector<vector<int>> lower, upper;
        for (const auto& p : trees) {
            while (lower.size() >= 2 && cross(lower[lower.size()-2], lower[lower.size()-1], p) < 0) {
                lower.pop_back();
            }
            lower.push_back(p);
        }
        
        for (int i = trees.size() - 1; i >= 0; i--) {
            const auto& p = trees[i];
            while (upper.size() >= 2 && cross(upper[upper.size()-2], upper[upper.size()-1], p) < 0) {
                upper.pop_back();
            }
            upper.push_back(p);
        }
        
        set<vector<int>> hull;
        for (int i = 0; i < (int)lower.size() - 1; i++) hull.insert(lower[i]);
        for (int i = 0; i < (int)upper.size() - 1; i++) hull.insert(upper[i]);
        
        return vector<vector<int>>(hull.begin(), hull.end());
    }
};