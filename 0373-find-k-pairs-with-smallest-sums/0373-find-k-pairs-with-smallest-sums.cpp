class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        if (nums1.empty() || nums2.empty()) return {};
        
        using T = tuple<int, int, int>; // sum, i, j
        priority_queue<T, vector<T>, greater<T>> pq;
        for (int i = 0; i < min(k, (int)nums1.size()); i++) {
            pq.emplace(nums1[i] + nums2[0], i, 0);
        }
        
        vector<vector<int>> result;
        while (!pq.empty() && (int)result.size() < k) {
            auto [sum, i, j] = pq.top();
            pq.pop();
            result.push_back({nums1[i], nums2[j]});
            if (j + 1 < (int)nums2.size()) {
                pq.emplace(nums1[i] + nums2[j + 1], i, j + 1);
            }
        }
        
        return result;
    }
};