class Solution:
    def countPalindromicSubsequences(self, S: str) -> int:
        MOD = 1000000007
        n = len(S)
        # dp[i][j] = number of different palindromic subsequences in S[i..j]
        dp = [[0]*n for _ in range(n)]
        for i in range(n):
            dp[i][i] = 1
        # precompute next and prev occurrence for each char
        # next_pos[i][c] = smallest index >= i where S[index] == c, else n
        # prev_pos[i][c] = largest index <= i where S[index] == c, else -1
        next_pos = [[n]*4 for _ in range(n)]
        prev_pos = [[-1]*4 for _ in range(n)]
        for c in range(4):
            ch = chr(ord('a') + c)
            # fill next_pos from right
            nxt = n
            for i in range(n-1, -1, -1):
                if S[i] == ch:
                    nxt = i
                next_pos[i][c] = nxt
            # fill prev_pos from left
            prv = -1
            for i in range(n):
                if S[i] == ch:
                    prv = i
                prev_pos[i][c] = prv
        for length in range(2, n+1):
            for i in range(n-length+1):
                j = i + length - 1
                if S[i] != S[j]:
                    dp[i][j] = dp[i+1][j] + dp[i][j-1] - dp[i+1][j-1]
                else:
                    # same char
                    left = next_pos[i][ord(S[i])-ord('a')]
                    right = prev_pos[j][ord(S[i])-ord('a')]
                    if left > right:  # no same char inside
                        dp[i][j] = dp[i+1][j-1] * 2 + 2
                    elif left == right:  # exactly one same char inside
                        dp[i][j] = dp[i+1][j-1] * 2 + 1
                    else:  # at least two same chars inside
                        dp[i][j] = dp[i+1][j-1] * 2 - dp[left+1][right-1]
                dp[i][j] = (dp[i][j] + MOD) % MOD
        return dp[0][n-1]
