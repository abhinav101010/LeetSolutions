class Solution:
    def minimumOperationsToMakeKPeriodic(self, word, k):
        n = len(word)
        return n // k - max(Counter(word[i : i + k] for i in range(0, n, k)).values())
