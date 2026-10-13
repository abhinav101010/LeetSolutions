from typing import List

class Solution:
    def wordsTyping(self, sentence: List[str], rows: int, cols: int) -> int:
        s = ' '.join(sentence) + ' '
        n = len(s)
        dp = [0] * n
        for i in range(n - 1, -1, -1):
            if s[i] == ' ':
                dp[i] = 1
            elif i + cols >= n:
                dp[i] = 0
            else:
                dp[i] = dp[i + cols] + 1
        res = 0
        pos = 0
        for _ in range(rows):
            res += dp[pos]
            pos = (pos + cols) % n
        return res // len(sentence)