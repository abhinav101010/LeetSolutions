class Solution:
    def maxScoreSightseeingPair(self, values):
        res = 0
        best_i = values[0] + 0
        for j in range(1, len(values)):
            res = max(res, best_i + values[j] - j)
            best_i = max(best_i, values[j] + j)
        return res
