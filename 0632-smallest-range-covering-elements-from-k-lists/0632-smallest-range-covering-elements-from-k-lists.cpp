class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size();
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
        int maxVal = -1000000000;
        for (int i = 0; i < k; i++) {
            pq.emplace(nums[i][0], i, 0);
            maxVal = max(maxVal, nums[i][0]);
        }
        
        vector<int> ans = {get<0>(pq.top()), maxVal};
        while (true) {
            auto [minVal, rowIdx, colIdx] = pq.top();
            pq.pop();
            if (colIdx + 1 == nums[rowIdx].size()) break;
            int nextVal = nums[rowIdx][colIdx + 1];
            pq.emplace(nextVal, rowIdx, colIdx + 1);
            maxVal = max(maxVal, nextVal);
            if (maxVal - get<0>(pq.top()) < ans[1] - ans[0]) {
                ans[0] = get<0>(pq.top());
                ans[1] = maxVal;
            }
        }
        
        return ans;
    }
};