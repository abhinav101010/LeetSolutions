class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<pair<int, int>> startIdx;
        for (int i = 0; i < n; i++) {
            startIdx.emplace_back(intervals[i][0], i);
        }
        
        sort(startIdx.begin(), startIdx.end());
        vector<int> starts(n);
        for (int i = 0; i < n; i++) starts[i] = startIdx[i].first;
        
        vector<int> result(n);
        for (int i = 0; i < n; i++) {
            int idx = lower_bound(starts.begin(), starts.end(), intervals[i][1]) - starts.begin();
            result[i] = idx < n ? startIdx[idx].second : -1;
        }
        return result;
    }
};