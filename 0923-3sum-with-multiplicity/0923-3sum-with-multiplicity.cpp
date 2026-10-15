class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        const int MOD = 1000000007;
        int n = arr.size();
        long ans = 0;
        for (int i = 0; i < n; ++i) {
            unordered_map<int,int> cnt;
            int need = target - arr[i];
            for (int j = i+1; j < n; ++j) {
                int complement = need - arr[j];
                ans = (ans + cnt[complement]) % MOD;
                cnt[arr[j]]++;
            }
        }
        return (int)ans;
    }
};
