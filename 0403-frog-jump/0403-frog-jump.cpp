class Solution {
public:
    bool canCross(vector<int>& stones) {
        unordered_set<int> stoneSet(stones.begin(), stones.end());
        unordered_map<long long, bool> memo;
        return dfs(0, 0, stones.back(), stoneSet, memo);
    }
    
private:
    bool dfs(int pos, int k, int target, unordered_set<int>& stoneSet, unordered_map<long long, bool>& memo) {
        if (pos == target) return true;
        long long key = ((long long)pos << 32) | (unsigned int)k;
        if (memo.count(key)) return memo[key];
        
        for (int step = k - 1; step <= k + 1; step++) {
            if (step > 0 && stoneSet.count(pos + step)) {
                if (dfs(pos + step, step, target, stoneSet, memo)) {
                    memo[key] = true;
                    return true;
                }
            }
        }
        
        memo[key] = false;
        return false;
    }
};