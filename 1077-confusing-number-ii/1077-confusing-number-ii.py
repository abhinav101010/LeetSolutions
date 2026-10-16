class Solution:
    def confusingNumberII(self, n):
        mp = {0:0,1:1,6:9,8:8,9:6}
        digits = [0,1,6,8,9]
        self.ans = 0
        def dfs(num):
            if num > n:
                return
            # rotated
            r, t = 0, num
            while t:
                r = r*10 + mp[t%10]
                t //= 10
            if r != num:
                self.ans += 1
            for d in digits:
                if num == 0 and d == 0:
                    continue
                dfs(num*10 + d)
        dfs(0)
        return self.ans
