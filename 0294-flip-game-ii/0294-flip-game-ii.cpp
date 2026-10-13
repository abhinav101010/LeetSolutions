class Solution {
public:
    unordered_map<string, bool> memo;
    
    bool canWin(string currentState) {
        if (memo.count(currentState)) return memo[currentState];
        for (int i = 0; i < (int)currentState.size() - 1; i++) {
            if (currentState[i] == '+' && currentState[i + 1] == '+') {
                currentState[i] = '-';
                currentState[i + 1] = '-';
                if (!canWin(currentState)) {
                    currentState[i] = '+';
                    currentState[i + 1] = '+';
                    memo[currentState] = true;
                    return true;
                }
                currentState[i] = '+';
                currentState[i + 1] = '+';
            }
        }
        memo[currentState] = false;
        return false;
    }
};