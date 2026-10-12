from functools import lru_cache

class Solution:
    def numDecodings(self, s: str) -> int:
        MOD = 10**9 + 7
        
        @lru_cache(None)
        def dp(i, prev):
            if i == len(s):
                return 1
            res = 0
            if prev and s[i] != '*':
                num = prev * 10 + int(s[i])
                if num >= 1 and num <= 26:
                    res = (res + dp(i + 1, 0)) % MOD
            if not prev:
                if s[i] != '*':
                    if s[i] != '0':
                        res = (res + dp(i + 1, 0) + dp(i + 1, int(s[i]))) % MOD
                    else:
                        res = (res + dp(i + 1, 0)) % MOD
                else:
                    res = (res + dp(i + 1, 0)) % MOD  # 1-9 as single
                    res = (res + 9 * dp(i + 1, 0)) % MOD  # 1-9
                    res = (res + dp(i + 1, 1) + dp(i + 1, 2)) % MOD  # 1,2
            return res
        
        return dp(0, 0)