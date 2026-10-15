class Solution:
    def distinctSubseqII(self, s: str) -> int:
        MOD = 10**9 + 7
        dp = 1  # empty subsequence
        last = [0]*26
        for ch in s:
            idx = ord(ch) - ord('a')
            prev = dp
            dp = (dp * 2) % MOD
            dp = (dp - last[idx] + MOD) % MOD
            last[idx] = prev
        return (dp - 1) % MOD  # exclude empty
