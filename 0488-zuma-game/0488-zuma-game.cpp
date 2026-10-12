class Solution {
private:
    unordered_map<string, int> memo;
    array<int, 26> handCount;
    
    string clean(string s) {
        int i = 0;
        while (i < (int)s.size()) {
            int j = i;
            while (j < (int)s.size() && s[j] == s[i]) j++;
            if (j - i >= 3) {
                return clean(s.substr(0, i) + s.substr(j));
            }
            i = j;
        }
        return s;
    }
    
    int dfs(string board) {
        board = clean(board);
        if (board.empty()) return 0;
        if (memo.count(board)) return memo[board];
        
        int ans = INT_MAX;
        int i = 0;
        while (i < (int)board.size()) {
            int j = i;
            while (j < (int)board.size() && board[j] == board[i]) j++;
            int need = 3 - (j - i);
            if (handCount[board[i] - 'A'] >= need) {
                handCount[board[i] - 'A'] -= need;
                int nextSteps = dfs(board.substr(0, i) + board.substr(j));
                if (nextSteps != -1) ans = min(ans, nextSteps + need);
                handCount[board[i] - 'A'] += need;
            }
            i = j;
        }
        
        memo[board] = ans == INT_MAX ? -1 : ans;
        return memo[board];
    }

public:
    int findMinStep(string board, string hand) {
        handCount.fill(0);
        for (char c : hand) handCount[c - 'A']++;
        return dfs(board);
    }
};