class Solution:
    def waysToBuyPensPencils(self, total, cost1, cost2) :
        ans = 0
        for x in range(total // cost1 + 1):
            y = (total - (x * cost1)) // cost2 + 1
            ans += y
        return ans
