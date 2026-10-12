class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> groupId(n);
        int currId = 0;
        for (int i = 1; i < n; i++) {
            if (nums[i] - nums[i - 1] > maxDiff) {
                currId++;
            }
            groupId[i] = currId;
        }
        vector<bool> ans;
        for (auto& q : queries) {
            ans.push_back(groupId[q[0]] == groupId[q[1]]);
        }
        return ans;
    }
};