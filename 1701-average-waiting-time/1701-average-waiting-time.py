class Solution:
    def averageWaitingTime(self, customers) :
        tot = t = 0
        for a, b in customers:
            t = max(t, a) + b
            tot += t - a
        return tot / len(customers)
