class Solution {
private:
    int m, n, total;
    unordered_map<int, int> map;

public:
    Solution(int m, int n) : m(m), n(n), total(m * n) {}

    vector<int> flip() {
        int r = rand() % total;
        total--;
        int idx = map.count(r) ? map[r] : r;
        map[r] = map.count(total) ? map[total] : total;
        return {idx / n, idx % n};
    }

    void reset() {
        total = m * n;
        map.clear();
    }
};