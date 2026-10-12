class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> res(n);
        int idx = 0;
        for (int i = 1; i <= n - k; i++) res[idx++] = i;
        for (int i = 0; i <= k; i++) {
            if (i % 2 == 0) res[idx++] = n - k + i / 2;
            else res[idx++] = n - i / 2;
        }
        return res;
    }
};