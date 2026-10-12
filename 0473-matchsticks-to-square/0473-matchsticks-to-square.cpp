class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        if (matchsticks.size() < 4) return false;
        int total = 0;
        for (int m : matchsticks) total += m;
        if (total % 4 != 0) return false;
        int target = total / 4;
        sort(matchsticks.rbegin(), matchsticks.rend());
        if (matchsticks[0] > target) return false;
        
        vector<int> sides(4, 0);
        return dfs(matchsticks, 0, target, sides);
    }
    
private:
    bool dfs(vector<int>& matchsticks, int index, int target, vector<int>& sides) {
        if (index == (int)matchsticks.size()) {
            return sides[0] == target && sides[1] == target && sides[2] == target;
        }
        
        for (int i = 0; i < 4; i++) {
            if (sides[i] + matchsticks[index] <= target) {
                sides[i] += matchsticks[index];
                if (dfs(matchsticks, index + 1, target, sides)) return true;
                sides[i] -= matchsticks[index];
            }
            if (sides[i] == 0) break;
        }
        return false;
    }
};