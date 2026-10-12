class Solution {
private:
    unordered_map<string, int> memo;
    
    int dp(const string& ring, const string& key, int i, int j) {
        if (j == (int)key.size()) return 0;
        string memoKey = to_string(i) + "," + to_string(j);
        if (memo.count(memoKey)) return memo[memoKey];
        
        int minSteps = INT_MAX;
        for (int k = 0; k < (int)ring.size(); k++) {
            if (ring[k] == key[j]) {
                int diff = abs(k - i);
                int steps = min(diff, (int)ring.size() - diff) + 1;
                minSteps = min(minSteps, steps + dp(ring, key, k, j + 1));
            }
        }
        
        memo[memoKey] = minSteps;
        return minSteps;
    }

public:
    int findRotateSteps(string ring, string key) {
        return dp(ring, key, 0, 0);
    }
};