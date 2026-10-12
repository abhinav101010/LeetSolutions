class Solution {
private:
    unordered_map<int, bool> memo;
    int maxChoosable;
    int desired;

    bool dfs(int used, int total) {
        if (memo.count(used)) return memo[used];
        
        for (int i = 1; i <= maxChoosable; i++) {
            if ((used & (1 << i)) == 0) {
                if (total + i >= desired || !dfs(used | (1 << i), total + i)) {
                    memo[used] = true;
                    return true;
                }
            }
        }
        
        memo[used] = false;
        return false;
    }

public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        maxChoosable = maxChoosableInteger;
        desired = desiredTotal;
        if (maxChoosableInteger * (maxChoosableInteger + 1) / 2 < desiredTotal) return false;
        if (desiredTotal <= 0) return true;
        return dfs(0, 0);
    }
};