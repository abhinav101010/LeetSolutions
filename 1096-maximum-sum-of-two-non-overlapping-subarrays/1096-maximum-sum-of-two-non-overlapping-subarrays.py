class Solution:
    def maxSumTwoNoOverlap(self, A, L, M):
        n = len(A)
        pref = [0] * (n + 1)
        for i in range(n):
            pref[i+1] = pref[i] + A[i]
        def sumx(i, j):
            return pref[j] - pref[i]
        ans = 0
        maxL = maxM = 0
        for i in range(L + M - 1, n):
            maxL = max(maxL, sumx(i - M - L + 1, i - M + 1))
            maxM = max(maxM, sumx(i - M - L + 1, i - L + 1))
            ans = max(ans, maxL + sumx(i - M + 1, i + 1), maxM + sumx(i - L + 1, i + 1))
        return ans
