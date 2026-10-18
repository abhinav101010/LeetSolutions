class Solution:
    def passThePillow(self, n, time):
        ans = k = 1
        for _ in range(time):
            ans += k
            if ans == 1 or ans == n:
                k *= -1
        return ans
