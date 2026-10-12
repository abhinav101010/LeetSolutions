class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        const int MOD = 1000000007;
        int m = (int)s.size();

        vector<int> pos, digits;
        for (int i = 0; i < m; i++) {
            if (s[i] != '0') {
                pos.push_back(i);
                digits.push_back(s[i] - '0');
            }
        }
        int n = (int)digits.size();

        vector<long long> prefixSum(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefixSum[i + 1] = prefixSum[i] + digits[i];
        }

        vector<long long> pow10(n + 1, 1);
        for (int i = 1; i <= n; i++) {
            pow10[i] = (pow10[i - 1] * 10) % MOD;
        }

        vector<long long> prefixVal(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefixVal[i + 1] = (prefixVal[i] * 10 + digits[i]) % MOD;
        }

        vector<int> ans;
        for (auto& q : queries) {
            int l = q[0], r = q[1];
            int left = lower_bound(pos.begin(), pos.end(), l) - pos.begin();
            int right = upper_bound(pos.begin(), pos.end(), r) - pos.begin();
            if (left == right) {
                ans.push_back(0);
                continue;
            }
            long long digitSum = prefixSum[right] - prefixSum[left];
            long long x = (prefixVal[right] - prefixVal[left] * pow10[right - left]) % MOD;
            if (x < 0) x += MOD;
            ans.push_back((int)((x * digitSum) % MOD));
        }
        return ans;
    }
};