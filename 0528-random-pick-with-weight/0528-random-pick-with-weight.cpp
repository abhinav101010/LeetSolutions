class Solution {
private:
    vector<int> prefix;

public:
    Solution(vector<int>& w) {
        prefix.resize(w.size());
        int total = 0;
        for (int i = 0; i < (int)w.size(); i++) {
            total += w[i];
            prefix[i] = total;
        }
    }

    int pickIndex() {
        int target = rand() % prefix.back() + 1;
        int left = 0, right = prefix.size() - 1;
        while (left < right) {
            int mid = (left + right) / 2;
            if (prefix[mid] < target) left = mid + 1;
            else right = mid;
        }
        return left;
    }
};