class Solution:
    def timeRequiredToBuy(self, tickets, k):
        ans = 0
        for i, x in enumerate(tickets):
            ans += min(x, tickets[k] if i <= k else tickets[k] - 1)
        return ans
