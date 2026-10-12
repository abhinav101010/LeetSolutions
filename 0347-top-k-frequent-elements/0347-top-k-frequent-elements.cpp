class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        for (int num : nums) {
            count[num]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (auto& p : count) {
            pq.push({p.second, p.first});
            if (pq.size() > k) {
                pq.pop();
            }
        }

        vector<int> ans(k);
        for (int i = k - 1; i >= 0; i--) {
            ans[i] = pq.top().second;
            pq.pop();
        }
        return ans;
    }
};