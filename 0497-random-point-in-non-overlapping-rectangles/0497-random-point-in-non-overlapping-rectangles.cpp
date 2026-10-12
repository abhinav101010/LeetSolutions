class Solution {
private:
    vector<vector<int>> rects;
    vector<int> areas;
    int total;

public:
    Solution(vector<vector<int>>& rects) : rects(rects) {
        total = 0;
        for (const auto& r : rects) {
            int area = (r[2] - r[0] + 1) * (r[3] - r[1] + 1);
            total += area;
            areas.push_back(total);
        }
    }

    vector<int> pick() {
        int r = rand() % total + 1;
        int left = 0, right = areas.size() - 1;
        while (left < right) {
            int mid = (left + right) / 2;
            if (areas[mid] < r) left = mid + 1;
            else right = mid;
        }
        
        int x1 = rects[left][0], y1 = rects[left][1];
        int x2 = rects[left][2], y2 = rects[left][3];
        int x = x1 + rand() % (x2 - x1 + 1);
        int y = y1 + rand() % (y2 - y1 + 1);
        return {x, y};
    }
};