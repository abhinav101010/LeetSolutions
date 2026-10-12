from collections import Counter
from typing import List

class Solution:
    def findMinStep(self, board: str, hand: str) -> int:
        hand_count = Counter(hand)
        memo = {}
        
        def clean(s):
            i = 0
            while i < len(s):
                j = i
                while j < len(s) and s[j] == s[i]:
                    j += 1
                if j - i >= 3:
                    return clean(s[:i] + s[j:])
                i = j
            return s
        
        def dfs(board):
            board = clean(board)
            if not board:
                return 0
            if board in memo:
                return memo[board]
            
            ans = float('inf')
            i = 0
            while i < len(board):
                j = i
                while j < len(board) and board[j] == board[i]:
                    j += 1
                need = 3 - (j - i)
                if hand_count[board[i]] >= need:
                    hand_count[board[i]] -= need
                    next_steps = dfs(board[:i] + board[j:])
                    if next_steps != -1:
                        ans = min(ans, next_steps + need)
                    hand_count[board[i]] += need
                i = j
            
            memo[board] = -1 if ans == float('inf') else ans
            return memo[board]
        
        return dfs(board)